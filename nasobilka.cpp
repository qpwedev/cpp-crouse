#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printMultiplication(int number){
    for (size_t i = 1; i <= 10; ++i)
        cout << i << " * " << number << " = " << i*number << endl;  
}

void processArgs(const vector<string>& a){
    for (size_t i = 1; i < a.size(); ++i)
        printMultiplication(stoi(a[i]));
        cout << "------------" << endl; 
}

int main(int argc, char* * argv){
    vector<string> arg(argv, argv+argc);
    if (arg.size() < 2){
        cout << "Usage: myprg parameters" << endl;
        return 8;
    }

    processArgs(arg);
    return 0;
}
