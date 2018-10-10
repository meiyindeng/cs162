#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
ifstream inFile;
ofstream outFile;
    outFile << fixed << showpoint;
    outFile << setprecision(2);
int linenum = 1;
struct EmployeeType
{
    string name;
    int ID;
    double hours;
    double payRate;
    double grossPay;
};

EmployeeType employeeInfo;
employeeInfo.grossPay = 0.0;



inFile.open("employees.txt");


    inFile >> employeeInfo.name;


    inFile >> employeeInfo.ID;
    inFile >> employeeInfo.hours;
    inFile >> employeeInfo.payRate;



outFile.open("employeeInfo.out");

    outFile << "name: " << setw(20) << employeeInfo.name << endl;
    outFile << "ID: " << setw(6) << employeeInfo.ID << endl;
    outFile << "hours: " << setw(6) << employeeInfo.hours << endl;
    outFile << "payrate: " << setw(6) << employeeInfo.payRate << endl;










inFile.close();
outFile.close();

return 0;
}
