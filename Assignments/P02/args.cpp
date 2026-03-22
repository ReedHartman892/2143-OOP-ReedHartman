#include <iostream>
#include <string>

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
    const int valid_rotations[4] = {0, 90, 180, 270};

    public:
    // ---- constructor ----
    // default constructor with default values
    Args() : grayscale(false), blur(false), flipH(false), flipV(false),
             brighten(false), brighten_value(0), rotate(false), rotate_value(0)
    { cout << "why are you calling this" << endl; }
    
    // parameterized constructor
    Args(int argc, char* argv[]) : grayscale(false), blur(false), flipH(false), flipV(false),
                                   brighten(false), brighten_value(0), rotate(false), rotate_value(0)
    {
        // STEP 1: parse filenames
        // assumes the 1st arg is the input and the 2nd arg is the output
        
        // checks if length of argv is long enough for there to be 2 filenames.
        if (argc < 2) {
            cout << "Error: missing filenames!" << endl;
            cout << "Usage: ./args <input> <output> [options]" << endl;
            cout << "Program aborted" << endl; exit(1); // abort program
        }
        if (argc < 3) {
            cout << "Error: missing output" << endl;
            cout << "Usage: ./args <input> <output> [options]" << endl;
            cout << "Program aborted" << endl; exit(1); // abort program
        }
        // assign directory paths
        inputPath = argv[1];
        outputPath = argv[2];
        /* 
        NOTE: for true functionality, you'd need to search files to check
        if the file paths exist. However, for this assignment, that wasn't required. 
        Meaning the program assumes that inputPath and outputPath are real.
        */

        // test ouputs
        //cout << "Input file: " << inputPath << endl;
        //cout << "Output file: " << outputPath << endl;
        
        /*
        if (argc == 3){
            cout << "Error: no options chosen!" << endl;
            cout << "(insert list of options here)" << endl;
            cout << "Program aborted" << endl;
            exit(1);
        }
        */
        // flag checks
        for (int i = 3; i < argc; i++) {
            string arg = string(argv[i]);

            if (arg == "--grayscale" || arg == "-g") {setGrayscale(true);}
            else if (arg == "--blur" || arg == "-l") {setBlur(true);}
            else if (arg == "--flipH" || arg == "-h") {setFlipH(true);}
            else if (arg == "--flipV" || arg == "-v") {setFlipV(true);}
            
            // parameterized argument parsing
            // first two else ifs are a standard parse 
            else if (arg == "--brighten" || arg == "-b")
            {
                setBrighten(true);

                // ERROR: No next argument/position for command
                if (i + 1 >= argc) {
                    cout << "Error: \"" << arg << "\" requires an integer value" << endl;
                    cout << "Program aborted" << endl; exit(1); // abort program
                }
                
                setBrightenValue(parseInt(argv[i+1]));
                i++; // skip next argument
            }

            else if (arg == "--rotate" || arg == "-r")
            {
                setRotate(true);

                // ERROR: No next argument/position for command
                if (i + 1 >= argc) {
                    cout << "Error: \"" << arg << "\" requires an integer value" << endl;
                    cout << "Program aborted" << endl; exit(1); // abort program
                }

                setRotateValue(parseInt(argv[i+1]));
                i++; // skip next argument
            }

            // below is the parse for equal-signed arguments (weird)
            else if (hasEqualSign(arg)) {
                if (parseArg(arg) == "--brighten" || parseArg(arg) == "-b"){
                    setBrighten(true);
                    setBrightenValue(parseInt(arg.substr(arg.find('=')+1, arg.size())));
                }
                else if (parseArg(arg) == "--rotate" || parseArg(arg) == "-r") {
                    setRotate(true);
                    setRotateValue(parseInt(arg.substr(arg.find('=')+1, arg.size())));
                }
                else {
                    cout << "Error: " << arg << " is not a valid argument" << endl;
                    cout << "Program aborted" << endl; exit(1);
                }
            }
            
            else // output if the argument is bad or not applicable
            {
                cout << "Error: " << arg << " is not a valid argument" << endl;
                cout << "Program aborted" << endl; exit(1);
            }
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
        if (bv > max_bright || bv < min_bright) {
            cout << "Error: \"--brighten\" must be between [-255,255]" << endl;
            cout << "Program aborted" << endl; exit(1); // abort program
        }
        brighten_value = bv;
    }

    void setRotate(bool r){rotate = r;}

    void setRotateValue(int rv){
        bool valid = false;
        // keep rotation_value between {0, 90, 180, 270}
        for (int v : valid_rotations) {
            if (rv == v) {
                valid = true;
                break;
            }
        }
        if(valid) { rotate_value = rv; }
        else { 
            cout << "Error: Invalid rotate value " << rv << ". Must be 0, 90, 180, or 270." << endl;
            cout << "Program aborted" << endl; exit(1); // abort program
        }
    }

    // ---- methods ----
    int parseInt(const string& str) {
        //cout << "parseInt: " << str << endl;
        try {
            return stoi(str);
        }
        catch (const invalid_argument& e) {
            cout << "Error: invalid or missing integer for command" << endl;
            cout << "Program aborted" << endl; exit(1); // abort program
            return 0;
        }
        catch (const out_of_range& e) {
            cout << "Error: argument out of range: " << endl;
            cout << "Program aborted" << endl; exit(1); // abort program
            return 0;
        }
    };

    // parses the flags from the rest of the argument when it has an equal sign
    string parseArg(string str) { return str.substr(0, str.find('=')); };

    // detect if a arg uses an equal sign
    bool hasEqualSign(string str){
        if (str.find('=') == string::npos) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main(int argc, char** argv){
    Args test = Args(argc, argv);
    cout << "INPUT  : " << test.getInputPath() << endl;
    cout << "OUTPUT : " << test.getOutputPath() << endl;

    cout << "FLAGS  :";
    if(test.getGrayscale()) {cout << " grayscale";}
    if(test.getBlur())      {cout << " blur";}
    if(test.getFlipH())     {cout << " flipH";}
    if(test.getFlipV())     {cout << " flipV";}
    cout << endl;

    cout << "PARAMS :";
    if(test.getBrighten())  {cout << " brighten=" << test.getBrightenValue();}
    if(test.getRotate())    {cout << " rotate=" << test.getRotateValue();}
    cout << endl;
}