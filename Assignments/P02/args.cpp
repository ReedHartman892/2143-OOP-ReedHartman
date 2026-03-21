#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Args {
    // filenames
    string inputPath;
    string outputPath;
    
    // flags
    bool grayscale, blur, flipH, flipV;
    bool brighten; int brighten_value;
    bool rotate; int rotate_value;
    
    // parameter restrictions
    const int min_bright = -255;
    const int max_bright = 255;
    const int valid_rotations[4];

    public:
    // ---- constructor ----
    // default constructor with default values
    Args() : grayscale(false), blur(false), flipH(false), flipV(false),
             brighten(false), brighten_value(0), rotate(false), rotate_value(0),
             valid_rotations({0, 90, 180, 270})
    { cout << "why are you calling this" << endl; }
    
    // parameterized constructor
    Args(int argc, char* argv[]) : grayscale(false), blur(false), flipH(false), flipV(false),
                                   brighten(false), brighten_value(0), rotate(false), rotate_value(0),
                                   valid_rotations({0, 90, 180, 270})
    {
        // STEP 1: parse filenames
        // assumes the 1st arg is the input and the 2nd arg is the output
        
        // checks if length of argv is long enough for there to be 2 filenames.
        if (argc < 3) {
            cout << "Error: missing filenames!" << endl;
            cout << "Usage: ./args <input> <output> [options]" << endl;
            exit (1);
        }
        // assign directory paths
        inputPath = argv[1];
        outputPath = argv[2];
        /* 
        NOTE: for true functionality, you'd need to search files to check
        if the file paths exist. However, for this assignment, that wasn't required. 
        Meaning the program assumes that inputPath and outputPath are real.
        */
        // checks if inputPath and outputPath are structured like commands.
        /* code here */

        // test ouputs
        cout << "Input file: " << inputPath << endl;
        cout << "Output file: " << outputPath << endl;
        
        if (argc == 3){
            cout << "Error: no options chosen!" << endl;
            cout << "(insert list of options here)" << endl;
            exit(1);
        }

        // flag checks
        if (string (argv[3]) == "--grayscale") {
            setGrayscale(true);
        }
    }

    // ---- getters ----
    string getInputPath(){return inputPath;}
    string getOutputPath(){return outputPath;}
    
    bool getGrayscale(){return grayscale;}
    bool getBlur(){return blur;}
    bool getFlipH(){return flipH;}
    bool getFlipV(){return flipV;}

    bool getBrighten(){return brighten;}
    int getBrightenValue(){return brighten_value;}

    bool getRotate(){return rotate;}
    int getRotateValue(){return rotate_value;}

    // ---- setters ----
    void setInputPath(string ip){inputPath = ip;}
    void setOutputPath(string op){outputPath = op;}

    void setGrayscale(bool g){grayscale = g;}
    void setBlur(bool l){blur = l;}
    void setFlipH(bool h){flipH = h;}
    void setFlipV(bool v){flipV = v;}

    void setBrighten(bool b){brighten = b;}
    void setBrightenValue(int bv){
        // TODO: add functionality to keep brighten_value between min and max
        brighten_value = bv;
    }

    void setRotate(bool r){rotate = r;}
    void setRotateValue(int rv){
        // TODO add functionality to keep rotate_value between the 4 set values
        rotate_value = rv;
    }

    // ---- methods ----

};

int main(int argc, char** argv){
    Args test = Args(argc, argv);
    cout << "grayscale: " << test.getGrayscale() << endl;
    cout << "blur: " << test.getBlur() << endl;
    cout << "flipH: " << test.getFlipH() << endl;
    cout << "flipV: " << test.getFlipV() << endl;
    cout << "brighten: " << test.getBrighten() << endl;
    cout << "brighten_value: " << test.getBrightenValue() << endl;
    cout << "rotate: " << test.getRotate() << endl;
    cout << "rotate_value: " << test.getRotateValue() << endl;
}