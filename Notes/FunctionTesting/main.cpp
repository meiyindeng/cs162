#include <iostream>

using namespace std;


int main (){

 char word1[30] = "Apple";
 char word2[30] = "Banana";
    if(strcmp(word1, word2) != 0)
        {
            cout << "The words are NOT anagrams of each other" << endl;
        }
    else
        {
            cout << "The words are anagrams of each other" << endl;
        }

return 0;
}
