#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1
//
int main( int argc, char* argv[] )
{
    // just to get you started, this is how to refer to the arguments that were passed
    for (int arg = 0; arg < argc; ++arg){
            if (arg == 0){ //To get the file name
                cout << "program: " << argv[arg] << endl;
            } else{ //count all lines in the rest of the files 
                ifstream file (argv[arg]);
                if(file.is_open()){ //if the file can be open then count all the lines in the file 
                    string line;
                    int count = 0;
                    while (getline(file, line)){
                        count++;
                    }
                    cout << ' ' << argv[arg] << ": " << count << endl;
                } else { //To deal with those file failed to open/read.
                    cout << ' ' << argv[arg] << ": " << "-1" << endl;
                }
                file.close(); //close the file when we are done using it 
            }
    }
    exit(0); // this means that the program executed correctly!
}
