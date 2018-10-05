#include <iostream>

using namespace std;

int main()
{
    bool tryAgain = false;
    do{

    char word1[30];
    char word2[30];

        cout << "Enter the first word:" << endl;
        cin >> word1;

        cout << "Enter the second word:" << endl;
        cin >> word2;

        if (strlen(word1) != strlen(word2))
        {
            cout << "The words are NOT anagrams of each other"<< endl;
            return 0;
        }



        for (int index = 0; index < strlen(word1); index++)
        {
            for (int secondIndex = 0; secondIndex < strlen(word2); secondIndex ++)
            {

                    if (word1[index] == word2[secondIndex])
                        {
                            word2[secondIndex] = '*';
                            break;

                        }

            }

        }
        bool isAnagram = true;
        for (int x = 0; x < strlen(word2); x++)
        {
            if (word2[x] != '*')
            {
                isAnagram =  false;

            }

        }
            if (isAnagram == false)
            {
            cout << "The words are NOT anagrams of each other"<< endl;
            }
            else
            {

             cout << "The words are anagrams of each other"<< endl;
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

    return 0;
}
