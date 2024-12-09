#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function declarations
void saveData(int age, string name);
void generateBirthdayCard();

int main()
{
    string userName;
    int userAge;

    // Taking user input
    cout << "Please enter your name: ";
    cin >> userName;
    cout << "Please enter your age: ";
    cin >> userAge;

    saveData(userAge, userName);
    generateBirthdayCard();

    return 0;
}

void saveData(int age, string name)
{
    // Open file in write mode and store data
    ofstream file("Output1.txt");
    if (file.is_open())
    {
        file << name << "," << age;
        file.close();
    }
    else
    {
        cout << "Error opening file for writing!" << endl;
    }
}

void generateBirthdayCard()
{
    ifstream file("Output1.txt");
    string content;

    // Read data from the file
    if (file.is_open())
    {
        getline(file, content);
        file.close();
    }
    else
    {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    // Extract name and age from file data
    size_t delimiterPos = content.find(',');
    string name = content.substr(0, delimiterPos);
    string ageStr = content.substr(delimiterPos + 1);
    int age = stoi(ageStr);

    // Generate the birthday card based on age
    ofstream outputFile("Output2.txt");
    if (age % 2 == 0)
    {
        string border = "########################";
        string message = "## " + to_string(age) + " HB " + name + "! " + to_string(age) + " ##";

        cout << border << endl;
        cout << message << endl;
        cout << border << endl;

        if (outputFile.is_open())
        {
            outputFile << border << endl;
            outputFile << message << endl;
            outputFile << border << endl;
        }
    }
    else
    {
        string border = "********";
        string message = "* " + to_string(age) + " HB " + name + "! " + to_string(age) + " *";

        cout << border << endl;
        cout << message << endl;
        cout << border << endl;

        if (outputFile.is_open())
        {
            outputFile << border << endl;
            outputFile << message << endl;
            outputFile << border << endl;
        }
    }

    if (outputFile.is_open())
    {
        outputFile.close();
    }
}
