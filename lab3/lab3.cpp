#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct EmployeeType {
    char name [20];
    int ID;
    double hours;
    double payRate;
    double grossPay;

};

int main() {
    ifstream inFile;
    ofstream outFile;
    outFile << fixed << showpoint;
    outFile << setprecision(2);
    EmployeeType employeeInfo[100];


    inFile.open("employees.txt");
    if (!inFile) {
        cout << "could not open file" << endl;
    }


    int count = 0;
    char c = inFile.peek();
    while (!inFile.eof() && count <= 100 && c != '\n') {
        inFile.getline(employeeInfo[count].name, 20);
        inFile >> employeeInfo[count].ID;
        inFile.ignore(20, '\n');
        inFile >> employeeInfo[count].hours;
        inFile.ignore(20, '\n');
        inFile >> employeeInfo[count].payRate;
        inFile.ignore(20, '\n');
        count ++;
        c = inFile.peek();
    }



    outFile.open("employeeInfo.out");
    for (int i = 0; i <= 8; i++) {
        
        outFile << "name: " << employeeInfo[i].name << endl;
        outFile << "ID: " << employeeInfo[i].ID << endl;
        outFile << "hours: " << employeeInfo[i].hours << endl;
        outFile << "payrate: " << employeeInfo[i].payRate << endl;

    }

    outFile << "Calculating gross pay ..." << endl;
    for (int i = 0; i <= 9; i++) {
        employeeInfo[i].grossPay = employeeInfo[i].hours * employeeInfo[i].payRate;
        outFile << employeeInfo[i].name << "gross pay is " << employeeInfo[i].grossPay << endl;
    }


    outFile.close();

    outFile.open("grosspay.txt");
    for (int i = 0; i <=9; i++) {
        employeeInfo[i].grossPay = employeeInfo[i].hours * employeeInfo[i].payRate;
        outFile << employeeInfo[i].ID << " " << employeeInfo[i].grossPay << endl;

    }

    outFile.close();


        inFile.close();
    return 0;
}
