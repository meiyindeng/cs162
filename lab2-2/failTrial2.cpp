#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//This function sort string word1

    char * selectionSort  (string word)
    {
        int index;
        int smallestIndex;
        int location;
        int temp;
        int n = word.length();



        sort(word.begin(), word.end());
        char charArray[n+1];
        word.copy(charArray, word.size()+1);
        charArray[word.size()] = '\0';

        /*
        x = 0; index < length1 - 1; index++)
        {
            smallestIndex = index;
            for (location = index +1; location < length1; location++)
            {
                if (word[location] < word[smallestIndex])
                smallestIndex = location;
            }

            temp = word[smallestIndex];
            word[smallestIndex] = word[index];
            word[index] = temp;
        }
        */




        return charArray[];
    }


//This function compare word1 and word2
    int main()
    {
       /* bool tryAgain = false;
        do{

    //Limit of this function is it only allow words up to 30 character,
        string word1;
        string word2;
        int i;
        cout << "Enter the first word:" << endl;
        cin >> word1;

        cout << "Enter the second word:" << endl;
        cin >> word2;

        //turn string to char[]
        //char firstWord[word1.size()+1];
        //strcpy(firstWord, word1.c_str());

        //char secondWord[word2.size()+1];
        //strcpy(secondWord, word2.c_str());

        int length1 = strlen(word1) + 1;
        int length2 = strlen(word2) + 1;

        */

       char sorted1 []= selectionSort(word1);
       char sorted2 []= selectionSort(word2);
        //first see if with the length is the same

        /*for (i=0 ; i<length1 ; i++)
        {
            cout << word2[i];
        }
        if (length1 != length2)
        {
            cout << "The words are NOT anagrams of each other"<< endl;
        }

        //compare word1 with word2
            else if(strcmp(word1, word2) != 0)
            {
                cout << "The words are NOT anagrams of each other" << endl;
            }
            else
            {
                cout << "The words are anagrams of each other" << endl;
            }
            bool correctInput = false;
            string continuePromp;
            while (!correctInput)
            {
                cout << "Do you want to continue? (y or n)";
                cin >> continuePromp;
                if (continuePromp == "y" || continuePromp == "Y" || continuePromp == "n" || continuePromp == "N")
                {
                    correctInput = true;
                }
            }

            if (continuePromp== "y"|| continuePromp =="Y")
            {
                tryAgain = true;
            }
            else
            {
                tryAgain = false;
            }
        }
        while (tryAgain);

        */

return 0;

}


