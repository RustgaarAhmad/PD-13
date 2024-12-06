#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string extractField(const string& record, int fieldIndex) {
    stringstream ss(record);
    string field;
    int currentField = 1;

    while (getline(ss, field, ',')) {
        if (currentField == fieldIndex) {
            return field;
        }
        currentField++;
    }
    return "";
}

int main() {
    string name;
    int age = 0;
    fstream inputFile;

    inputFile.open("names.txt", ios::in);
    if (!inputFile.is_open()) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    string line;
    string finalResult;


    while (getline(inputFile, line)) {
        name = extractField(line, 1); 
        age = stoi(extractField(line, 2)); 

        // Generate a formatted result based on age
        string formattedResult;
        if (age % 2 == 0) {
            formattedResult = "####################\n# " + to_string(age) + " HB " + name + " !" + to_string(age) + " #\n####################";
        } else {
            formattedResult = "*******\n " + to_string(age) + " HB " + name + " !" + to_string(age) + " \n*******";
        }

        finalResult += formattedResult + "\n\n";
    }

    inputFile.close();


    fstream outputFile;
    outputFile.open("final.txt", ios::out);
    if (outputFile.is_open()) {
        outputFile << finalResult;
        outputFile.close();
    } else {
        cerr << "Could not open the output file!" << endl;
    }

    return 0;
}