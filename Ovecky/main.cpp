#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "reader.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<string> args(argv, argv + argc);

    Reader hi;
    ifstream file;
    file.open(args[1]);

    hi.readStream(file);

    cout << "znaku: " << hi.charCounter << endl;
    cout << "slov: " << hi.wordCounter << endl;
    cout << "vet: " << hi.sentenceCounter << endl;
    cout << "radku: " << hi.lineCounter << endl;
    cout << "cisel: " << hi.numberCounter << endl;
    cout << "soucet: " << hi.numberSum;

    return 0;
}
