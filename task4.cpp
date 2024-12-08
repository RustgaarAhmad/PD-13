#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string find_missing_chars(string str);
void save_to_file(string original, string missingChars);

int main() {
    string userInput;
    cout << "Enter a word: ";
    getline(cin, userInput);
    string missingChars = find_missing_chars(userInput);
    save_to_file(userInput, missingChars);
    return 0;
}

string find_missing_chars(string str) {
    string missingChars = "";
    for(int i = 0; i < 26; i++) {
        char currentChar = char(97 + i);
        bool isFound = false;
        for(int j = 0; j < str.length(); j++) {
            if(currentChar == str[j]) {
                isFound = true;
                break;
            }
        }
        if(!isFound) {
            missingChars += currentChar;
        }
    }
    return missingChars;
}

void save_to_file(string original, string missingChars) {
    fstream outputFile;
    outputFile.open("letters.txt", ios::out);
    outputFile << original << endl;
    outputFile << missingChars << endl;
    outputFile.close();
    cout << "Remaining letters: " << missingChars << endl;
}
