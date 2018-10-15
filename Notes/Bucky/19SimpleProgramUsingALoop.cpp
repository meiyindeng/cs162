#include <iostream>
using namespace std;

int main()
{
	//number of times enter
	int x = 1;
	// number entered
	int number;
	int total = 0;
	cout << "enter 5 number" << endl;
	while (x<=5){
		cin >> number;
		total = total + number;
		x++;
		
	}
	cout << "total: " << total << endl;
	return 0;
}
