/*****************************/
// Reed Hartman
// Terry Griffin
// Object-Oriented Programming
// March 21st, 2026
/*****************************/

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "termcolor.hpp"
#include "stb_image.h"
#include "stb_image_write.h"

using namespace termcolor;

// ------------------------------------------------------------
// Program 2 (Edited from Program 1):
// - Uses argv[1] argv[2] for input/output
// - Loads an image, converts it to grayscale, saves as PNG
// (to be) supported flags:
// - --grayscale (-g)
// - --blur (-l)
// - --flipH (-h)
// - --flipV (-v)
// - --brighten N (-b [-255-255])
// - --rotate N (-r {0, 90, 180, 270})
// ------------------------------------------------------------

// This section here is used for opening the file.
bool open_file_default_app(const std::string& path) {
#if defined(_WIN32)
    std::string cmd = "start \"\" '\"" + path + "\"";
#elif defined(_APPLE_)
    std::string cmd = open \"" + path + "\"";
#else
    std::string cmd = "xdg-open \"" + path + "\"";
#endif
    return std::system(cmd.c_str()) == 0;
}

// class for tracking the arguments passed into main
class Args {
    private:
        std::string inputPath; // input file
        std::string outputPath; // output file
        bool grayscale, blur, flipH, flipV;
        bool use_brighten; int brighten;
        bool use_rotate; int rotate;

    public:
        // Getters
        std::string getInputPath(){}
        std::string getOutputPath(){}

        bool getGrayscale(){}
        bool getBlur(){}
        bool getFlipH(){}
        bool getFlipV(){}
        bool getUseBright(){}
        bool getUseRotate(){}

        int getBrightAmt(){}
        int getRotateAmt(){}

        // Setters
        std::string setInputPath(){}
        std::string setOutputPath(){}

        bool setGrayscale(){}
        bool setBlur(){}
        bool setFlipH(){}
        bool setFlipV(){}
        bool setUseBright(){}
        bool setUseRotate(){}

        int setBrightAmt(){}
        int setRotateAmt(){}

        // Constructor
        Args() // default constructor
        {

        }

        Args(int argc, char* argv[]) // paramertized constructor 
        {
           for (int i = 0; i < argc; i++) {
                std::cout << i << ": " << argv[i] << std::endl;
            } 
        }
};

int main(int argc, char** argv) {

    // modified check to ensure the directory is correct.
    std::cout << "Current working directory: "
              << std::filesystem::current_path() << "\n";
    
    // argument check
    Args(argc);

    if (argc < 3) {
        std::cout << red << "Usage: " << blue
                  << "./imgtool <input_image> <output_image> [options]\n"
                  << reset;
        return 1;
    }

    std::string inputPath  = argv[1]; // 1st argument is the image the user wants to edit
    std::string outputPath = argv[2]; // 2nd argument is the name the edited image will have

    int width = 0, height = 0, channels_in_file = 0;

    // Force RGB (3 channels)
    unsigned char* data = stbi_load(inputPath.c_str(),
                                    &width,
                                    &height,
                                    &channels_in_file,
                                    3);

    if (!data) {
        std::cerr << red << "Failed to load image: " << reset << inputPath
                  << yellow << "\nReason: " << reset << stbi_failure_reason() << "\n";
        return 1;
    }

    const int channels = 3;
    const int totalPixels = width * height;

    std::cout << green << "Loaded image: " << reset << width << "x" << height
              << green << " channels: " << reset << channels << "\n";

    // Hardcoded grayscale (luminance)
    for (int i = 0; i < totalPixels; ++i) {
        int idx = i * channels;

        int r = data[idx + 0];
        int g = data[idx + 1];
        int b = data[idx + 2];

        int gray = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);

        // gray will already be in [0,255] for this formula
        unsigned char gr = static_cast<unsigned char>(gray);

        data[idx + 0] = gr;
        data[idx + 1] = gr;
        data[idx + 2] = gr;
    }

    // Save PNG
    if (!stbi_write_png(outputPath.c_str(),
                        width,
                        height,
                        channels,
                        data,
                        width * channels)) {

        std::cerr << red << "Failed to write output image: " << reset << outputPath << "\n";
        stbi_image_free(data);
        return 1;
    }

    stbi_image_free(data);
    
    std::cout << green << "Saved output to: " << reset << outputPath << "\n";
    
    std::cout << green << "Opening output in default viewer...\n" << reset;
    if (!open_file_default_app(outputPath)) {
        std::cout << "Warning: could not launch viewer automatically. \n";
    }
    return 0;
}