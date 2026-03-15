#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <string>
#include <filesystem>

#include "termcolor.hpp"
#include "stb_image.h"
#include "stb_image_write.h"

using namespace termcolor;

// ------------------------------------------------------------
// Program 1 (Starter):
// - Uses argv[1] argv[2] for input/output
// - Loads an image, converts it to grayscale, saves as PNG
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


int main(int argc, char* argv[]) {

    std::cout << "Current working directory: "
              << std::filesystem::current_path() << "\n";
    
    if (argc < 3) {
        std::cout << red << "Usage: " << blue
                  << "./imgtool <input_image> <output_image>\n"
                  << reset;
        return 1;
    }

    std::string inputPath  = argv[1];
    std::string outputPath = argv[2];

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