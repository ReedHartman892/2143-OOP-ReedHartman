#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flag {
    string  flag;    // in-line name of the command
    bool    params;  // set to true if flag has a parameter
    int     value; // parameterized amt
        // certain flags accept different amts.
    
    public:
        // constructor
        Flag(){} // default constructor
        Flag(const string& f) : flag(f), params(false){} // non-parameter-flag constructor
        Flag(const string& f, int v) : flag(f), params(true), value(v){} // parameterized-flag constructor
        
        // getters
        string getFlag() {return flag;}
        bool getParams() {return params;}
        int getValue() {return value;}

        // setters
        void setFlag(string f) {flag = f;}
        void setParams(bool p) {params = p;}
        void setValue(int a) {value = a;}
};

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

    /*static vector<Flag> parse(const vector<string>& unparsed_args){
        int argc = unparsed_args.size();
        vector<Flag> parsed_flags;
        for(int i = 0; i < argc; i++) {
            string flag_name = unparsed_args[i];
            // STEP 1: Check if unparsed flag's command is valid
            if (Args::isValid(flag_name)) {
                // invalid flag case
                cout << "Invalid Flag: " << unparsed_args[i];
                exit(1);
            }
            
            // STEP 2: Flag construction, 2 cases: parameterized and non-parameterized
            Flag f;
            if (Args::hasParams(flag_name)) {
                // parameterized flag
                f = Flag(flag_name, stoi(unparsed_args[i+1]));
                i++; // skip parameter
            }
            else // non-parameterized flag
            {
                f = Flag(flag_name);
            }
            parsed_flags.push_back(f);
            cout << i;
        }
        return parsed_flags;
    }*/
    static vector<Flag> parse(const vector<string>& unparsed_args){
        cout << "Unparsed contents of flag to be parsed:" << endl;
        for (int i = 0; i < unparsed_args.size(); i++){ // test loop
            cout << unparsed_args[i] << endl;
        }

        int argc = unparsed_args.size();
        vector<Flag> parsed_flags;

        for(int i = 0; i < argc; i++) {
            string flag_name = unparsed_args[i];

            // STEP 1: Validate

            cout << "flag name being parsed: " << flag_name << endl; // test
            
            if (!Args::isValid(flag_name)) {
                cout << "Invalid flag name: " << flag_name << endl;
                exit(1);
            }

            Flag f;

            // STEP 2: Construct
            cout << "Processed index: " << i << endl;
            if (!Args::hasParams(flag_name)) {
                if (i + 1 >= argc) {
                    // parameterized
                    cout << "Missing parameter for " << flag_name << endl;
                    exit(1);
                }

                f = Flag(flag_name, stoi(unparsed_args[i+1]));
                i++; // skip parameter
            }
            else { // non parameterized construction
                f = Flag(flag_name);
            }

            parsed_flags.push_back(f);
        }
        return parsed_flags;
    }

    // used to check for parameterized flags
    static bool hasParams(const string& flag) {
        return flag == "--brighten" || flag == "--b"
            || flag == "--rotate"   || flag == "--r";
    }
    // used to check if a flag is valid
    static bool isValid(const string& flag) {
        return flag == "--grayscale" || flag == "-g" ||
               flag == "--blur"      || flag == "-l" ||
               flag == "--flipH"     || flag == "-h" ||
               flag == "--flipV"     || flag == "-v" ||
               flag == "--brighten"  || flag == "-b" ||
               flag == "--rotate"    || flag == "-r";
    }
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
    vector<Flag> flagv = Args::parse(new_args);
    cout << "if you are reading this then it runs correctly but is busted another way.";
}