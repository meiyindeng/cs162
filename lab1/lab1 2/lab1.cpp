#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double balance;
    int years;
    double principal;
    double rate;
    bool isPrincipal;
    bool isRate;
    bool isYears;
    int counting = 1;

    isPrincipal = false;
    while (! isPrincipal){
    cout << "Enter the initial principal amount (between 1 and 100000) \n";
    cin >> principal;
    if (principal>=1 && principal <=100000){
       isPrincipal = true;
       }
    else if(principal < 1 || principal >100000){
            cout << "Invalid amount. Please re-enter \n";
            }
    }

    isRate = false;
    while(! isRate){
    cout << "Enter rate of return as a percentage (between 1 and 100): \n";
    cin >> rate;
    if (rate>=1 && rate<=100){
        isRate = true;}
    else if(rate < 1 || rate > 100){
        cout << "Invalid amount. Please re-enter \n";}
    }
    rate = rate / 100;

    isYears = false;
    while (! isYears){
    cout << "Enter number of years (between 1 and 20): \n";
    cin >> years;
    if (years>=1 && years<=20){
        isYears = true;}
    else if(years < 1 || years >20){
        cout << "Invalid amount. Please re-enter \n";}
    }


    cout << setw(3) << "YEAR";
    cout << setw(20) << "Amount" << endl;
    while (counting <= years){
    balance = principal * pow(1+rate/365, (counting*365));

    cout << setw(3) << counting;
    cout.setf(ios::fixed);
    cout << setw(20) << setprecision(2) << balance << endl;
    counting++;}
    return 0;
}
