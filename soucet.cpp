#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countNumbers(string line) {
    line += " ";
    int sum = 0;
    bool blankBefore = true;
    string strNumber = "";
    
	for (size_t i = 0; i < line.size(); i++){
        if (0 <= line[i]-'0' && line[i]-'0' <= 9 && blankBefore) {
            strNumber += line[i];
        }
        else {
            blankBefore =  line[i] != ' ' ? false : true;

            if (strNumber != "" && (line[i] == ',' || line[i] == ',' || line[i] == '!' || line[i] == '?' || line[i] == ' ')){
                sum += stoi(strNumber);
            }
            strNumber = "";
        }

    }
    
    return sum;
}

int main(int argc, char** argv) {
    string line;
    while (getline(cin, line)){
        cout << countNumbers(line) << endl;
    }
	return 0;
}
