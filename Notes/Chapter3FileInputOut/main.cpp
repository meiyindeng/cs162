#include <iostream>
//Step 1:
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const string SENTINEL = "End";

// Output produced by one program can be used as an input to other programs
// Get data directly from and save output directly to secondary storage.
// File: An area in secondary storage used to hold infomration.

//iostream:
    //used only for input from the standard input device and output to the standard output device
//fstream: Must declare variables (file stream variables)
    //used for file I/O. Contain definitions of 2 data types:
        //ifstream - input file stream and is similar to istream
        //ofstream - output fil stream and is similar to ostream
//5-Steps Process:
    // 1. Include the header file fstream in the program
    // 2. Declare file stream variables
    // 3. Associate the file stream variable with the I/O sources.
    // 4. Use the file stream variables with >>, <<. or other I/O functions
    // 5. Close the files.


int main()
{
    //Step 2:
    ifstream inFile;
    ofstream outFile;
    double test1, test2, test3, test4, test5;
    double average;
    string firstName;
    string lastName;



    //Step 3:
    //Ex: input variable names inData. Input file names prog.dat, to execute the function:
    inFile.open("/Users/meiyindeng/Documents/cs162/Notes/testscore.txt");

    //Ex: output variable names outData. Output file names prog.out, to execute the function:
    outFile.open("testscoreprog.out");
        //To add the output at the end of an existing file use the option ios::app
        //Ex: outData.open("prog.out", ios::app);

    //Step 4:
    //Use the file stream variable names that were declared
    //Ex: inData >> payRate;
        //Reads the data from the file prog.dat and stores it in the variable payRate.
    //Ex: outData << "The paycheck is: $" << pay << endl;
        //Stores the output-The paycheck is: $___ in the file prog.out

    //Input file called test.txt stores name and test result
    outFile << fixed << showpoint;
    outFile << setprecision(2);

    cout << "Processing data" << endl;

    inFile >> firstName;
    while (firstName != SENTINEL) {
    inFile >> lastName;
    outFile << "Student name: " << firstName << " " << lastName << endl;

    inFile >> test1 >> test2 >> test3 >> test4 >> test5;
    outFile << "Test scores: " << setw(6) << test1
    << setw(6) << test2
    << setw(6) << test3
    << setw(6) << test4
    << setw(6) << test5
    << endl;

    average = (test1 + test2 + test3 + test4 + test5) / 5.0;
    outFile << "Average test score: " << setw(6) << average << endl;

    inFile >> firstName;

        }



    inFile.close();
    outFile.close();

        //outFile << "Student name: " << firstName << " " << lastName << endl;


    //Step 5: Closing a file by using stream function close
        //inData.close();
        //outData.close();

    //Sample Page 165
    //Formating output
        //To fill with ... Ex: Movie Name: ...... "Journey to Mars"
        //cout << setfill('.') << left << setw(35) << "Movie Name: " << right << " " << movieName << endl;



    //inFile >> test1 >> test2 >> test3 >> test4 >> test5;
    //outFile << "Test score

    //cout << fixed << showpoint << setprecisions (2); -> to display output in 2 decimal places

    return 0;
}
