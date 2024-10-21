//Program Name: File Encryption
//Description: This program reads lines from a file and displays them with the line number. It then pauses at a point
//             and waits for user input to continue displaying the remaining lines.
//Author: Jarod Davis
//Date Last Modified: October 21, 2024

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFile;
    char inName[200];
    string inputLine = "";
    int lineNumber = 1;

    // Variables to count the lines and to wait for user input
    int lineCount = 0; 
    string pauseInput;

    cout << "Enter the input file name: ";
    cin >> inName;

    inFile.open(inName);

    if (!inFile)
    {
        cout << "Error opening " << inName << endl;
        return 1123;
    }

    // Ignore new line and ensure pause happens
    cin.ignore();

    while (!inFile.eof())
    {
        getline(inFile, inputLine, '\n');
        cout << setw(4) << right << lineNumber << ": " << inputLine << endl;

        lineNumber++;
        lineCount++;

        // Pause at line 24
        if (lineCount == 24)
        {
            cout << "Press Enter to continue..." << endl;

            // Wait for user to press Enter and restart line count
            getline(cin, pauseInput); 
            lineCount = 0;
        }
    }

    inFile.close();
    return 0;
}