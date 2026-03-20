#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Args {
    const vector<string> valid = {"--greyscale","--blur","--flipH","--flipV","--rotate","--brighten"};

    public:
    
    // optimizes argv into a new list to make handling diverse inputs and creating flags from them simplier.
    static vector<string> optimize(int argc, char** argv){
        vector<string> opt_args;
        for (int i = 3; i < argc; i++) {
            string arg = argv[i];
            if (arg.find('=') != string::npos) {
                // Case C, parameterized w/ '='
                size_t eq = arg.find('=');
                opt_args.push_back(arg.substr(0, eq));
                opt_args.push_back(arg.substr(eq + 1));
            }
            else if (Args::hasParams(arg)) {
                // Case B, parameterized w/o parameter (assume next argc)
                if (i + 1 >= argc) {
                    cout << "Error: missing parameter for " << arg << endl;
                    exit(1);
                }
                
                // this exists to keep stuff like "-r --blur" from passing
                string next = argv[i + 1];
                if (next[0] == '-') {
                    cout << "Error: expected parameter after " << arg << endl;
                    exit(1);
                }

                opt_args.push_back(arg);
                opt_args.push_back(argv[i + 1]);
                ++i;
            }
            else {
                // Case A, non-parameterized
                opt_args.push_back(arg);
            }

            cout << "Current args: ";
            for (const string& s : opt_args) {
                cout << "[" << s << "] ";
            }
            cout << endl;
        }
        return opt_args;
    }

    static vector<Flag> parse(int argc, const vector<string>& unparsed_args){
        vector<Flag> parsed_flags;
        cout << unparsed_args[1];
        /*
        for (int i = 0; i < argc; i++) {
            
            // STEP 1: Check if unparsed flag's command is valid, if not, don't parse it and return an error message.
            if () {
                
            }

            // STEP 2: Construct a new flag, there's no functionality planned for these flags in the assignment, so i'm not making any.
            
            
            // STEP 3: check if the flag needs a parameter, and add that parameter to the flag if true
            if () {

                // PROCESS: look at argv[i+1] for the flag's parameter, the list is optimized to ensure this can work.

                // FAILSAFE 1: if argv[i+1] is checked and it isn't an integer value, simply forgo the parameterized flag from the final result, and report the error to the user.
                
                // FAILSAFE 2: check what parameterized flag it is to determine if that flag can be given that value of parameter
                // EX: "--rotate" can only have a parameter values {0, 90, 180, 270}
                // EX: "--brighten" can only have values between [-255, 255]

                // that should handle everything for parsing the flags.
            }
        }  */
    }

    // used to check for parameterized flags
    static bool hasParams(const string& flag) {
        return flag == "--brighten" || flag == "--b" ||
               flag == "--rotate"   || flag == "--r";
    }
    // used to check if a flag is valid
    static bool isValid(const string& flag) {
        return hasParams(flag) || flag == "--grayscale" || flag == "-g"
                               || flag == "--blur"      || flag == "-l"
                               || flag == "--flipH"     || flag == "-h"
                               || flag == "--flipV"     || flag == "-v"
                               || flag == "--brighten"  || flag == "-b"
                               || flag == "--rotate"    || flag == "-r";
    }
};

class Flag {
    string  flag;    // in-line name of the command
    bool    params;  // set to true if flag has a parameter
    int     amt = 0; // parameterized amt
        // certain flags accept different amts.
    
    public:
        // constructor
        Flag(){} // default constructor

        Flag(string f) : flag(f)
        {
            // check if this flag has a parameter
            setParams(Args::hasParams(getFlag()));
        };
        
        // getters
        string getFlag() {return flag;}
        bool getParams() {return params;}
        int getAmt() {return amt;}

        // setters
        void setFlag(string f) {flag = f;}
        void setParams(bool p) {params = p;}
        void setAmt(int a) {amt = a;}
};

int main (int argc, char** argv) {
    cout << argc << endl;
    cout << argv[0] << endl;

    // check for input and output file paths
    if (argc < 3) {
        cout << "Error: need a filename!" << endl;
        cout << "Usage: ./args <input> <output> [options]" << endl;
        exit (1);
    }
    else
    {
        string inputPath = argv[1];
        string outputPath = argv[2];
    }

    vector<string> new_args = Args::optimize(argc, argv);
    vector<Flag> flagv = Args::parse(argc, new_args);

}