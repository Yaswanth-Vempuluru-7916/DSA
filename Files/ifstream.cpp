#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Open the file "abc.txt" for reading
    ifstream inputFile("example.txt");

    // Variable to store each line from the file
    string line;

    // Read each line from the file and print it
    while (getline(inputFile, line)) {
        // Process each line as needed
        cout << line << endl;
        cout<<"*******************************\n";
    }

    // Always close the file when done
    inputFile.close();

    return 0;
}