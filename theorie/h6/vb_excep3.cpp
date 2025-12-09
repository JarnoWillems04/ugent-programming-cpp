#include <fstream>
#include <iostream>
#include <stdexcept>
#include "file_error.h"
using namespace std;

void openFile(const string &fname, ifstream &inFile) {
    inFile.open(fname);
    if (!inFile)
        throw file_error("Can't open file " + fname);
}

int main() {
    bool open = false;
    string file_name;
    ifstream in;
    int n = 0;

    while (!open && n<3) {
        cout << "Enter filename: ";
        cin >> file_name;
        try {
            openFile(file_name, in);
            open = true;
        }
        catch (const file_error &fe) {
            cout << fe.what() << endl;
            n += 1;
        }
    }
    if (open) 
        cout << file_name << " opened for reading." << endl;
   return 0;
}
