#include <iostream>

using namespace std;

int main()
{
   int *p;
   int array [6];
   p = array;
   *(p+1) = 1;
   *(p+2) = 3;
   *(p+3) = 5;
   *(p+4) = 7;
   *(p+5) = 9;

   cout << array[0];
   cout << array[1];



return 0;


}
