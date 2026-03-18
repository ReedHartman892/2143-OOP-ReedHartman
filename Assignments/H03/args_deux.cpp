#include <iostream>

using namespace std;

int main(int argc, char** argv){
    cout << argc << endl;

    if(argc < 2){
        cout << "Error: need filename\n";
        cout << "Usage: ./deux <filename>\n";
        exit(1);
    }

    // rest of the example is in the teacher's files
}