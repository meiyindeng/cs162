#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	for(x=1; x<20; x++){
	//use the random number and / 6 and give the remainder, because remainder can be 0, so add 1 to the number;
	srand(time(0));
	//use srand to change the algorithm, and use the time to change every second.
	cout << 1+(rand()%6) << endl;
       

        return 0;
}

