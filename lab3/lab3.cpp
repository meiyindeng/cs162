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
    char name[20];
    int ID;
    double hours;
    double payRate;

};

EmployeeType employeeInfo[100];

inFile.open("employees.txt");
    if(!inFile)
    {
        cout << "could not open file" << endl;
    }

int count = 0;
char c = inFile.peek();
while(!inFile.eof() && count <= 100 && c != '\n')
{
    inFile.getline(employeeInfo[count].name, 21);
    inFile >> employeeInfo[count].ID;
    inFile.ignore(21, '\n');
    inFile >> employeeInfo[count].hours;
    inFile.ignore(21, '\n');
    inFile >> employeeInfo[count].payRate;
    inFile.ignore(21, '\n');
    count++;
    c = inFile.peek();
}

inFile.close();



outFile.open("employeeInfo.out");
for (int i = 0; i <= 100; i++)
{
    outFile << "name: " << employeeInfo[i].name<< endl;
    outFile << "ID: " << employeeInfo[i].ID << endl;
    outFile << "hours: " << employeeInfo[i].hours << endl;
    outFile << "payrate: " << employeeInfo[i].payRate << endl;

}









outFile.close();

return 0;
}
