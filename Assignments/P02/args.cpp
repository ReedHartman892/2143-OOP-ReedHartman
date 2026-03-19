#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Args {

    public:
    
    // optimizes argv into a new list to make handling the inputs and creating the flags simplier.
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

    /*
    ifstream fin;
    fin.open ("input");

    int x;
    
    while (!fin.eof ()) {
        fin >> x;
        cout << x << " ";
    }
    while (fin >> x) {
        cout << x << " ";
    }
    */
}