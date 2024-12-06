#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string findMissingLetters(const string& input)
 {
    bool found[26] = {false};

    for (char ch : input) 
    {
        if (ch >= 'a' && ch <= 'z') 
        {
            found[ch - 'a'] = true;  
        }
    }
    string allLetters = "abcdefghijklmnopqrstuvwxyz";
    stringstream missingLetters;

    for (int i = 0; i < 26; ++i) 
    {
        if (!found[i]) {
            missingLetters << allLetters[i];  
        }
    }

    return missingLetters.str();  
}

int main()
 {

    string inputFileName = "alphabets.txt";
    
    ifstream inputFile(inputFileName);

    if (!inputFile)
     {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    string inputStr;
    getline(inputFile, inputStr);
    inputFile.close(); 

    string missingLetters = findMissingLetters(inputStr);

    ofstream outputFile(inputFileName, ios::app);

    if (!outputFile)
     {
        cout << "Error opening output file!" << endl;
        return 1;
    }

    outputFile << endl << missingLetters;
    outputFile.close();
    cout << "Missing letters: " << missingLetters << endl;

    return 0;
}
