#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int Maxline (string fileName){
    int count = 0;
    string line;
    ifstream inFile(fileName);
    while (getline(inFile, line)) {
        count++;
    }
    return count;


}

int main()
{

    int maxNumberOfLine;

    maxNumberOfLine = Maxline("/Users/meiyindeng/Documents/cs162/lab3/employees.txt");

    cout << "maximum number of line " << maxNumberOfLine;


    return 0;
}
