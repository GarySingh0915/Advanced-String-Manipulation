//Name: Gary Singh
//Date: 3/9/2020
//HW 4

#include <iostream>
#include <string> 
#include <sstream>
#include<vector>
#include <algorithm>

using namespace std;

class Phrase {     // The class

public:           // Access specifier
    string phrase;
    Phrase(string x) {     // Constructor

        phrase = x;
    }

    bool comparator(string a, string b);
    string sortedWords(string unsortedWords);
    string reversePhraseWords(string originalPhrase) {

        int i = originalPhrase.length() - 1;
        int start, end = i + 1;
        string result = "";

        while (i >= 0)
        {
            if (originalPhrase[i] == ' ')
            {
                start = i + 1;
                while (start != end)
                    result += originalPhrase[start++];

                result += ' ';
                end = i;
            }

            i--;
        }

        start = 0;

        while (start != end)
            result += originalPhrase[start++];

        return result;
    }


    string ROT13(string source) // convert to rot13 format
    {
        string transformed;
        for (size_t i = 0; i < source.size(); ++i) {
            if (isalpha(source[i])) {
                if ((tolower(source[i]) - 'a') < 14)
                    transformed.append(1, source[i] + 13);
                else
                    transformed.append(1, source[i] - 13);
            }
            else {
                transformed.append(1, source[i]);
            }
        }
        return transformed;
    }
         
    bool isVowel(char c)
    {

        return (c == 'A' || c == 'E' || c == 'I' ||

            c == 'O' || c == 'U' || c == 'a' ||

            c == 'e' || c == 'i' || c == 'o' ||

            c == 'u');

    }


    string pigLatin(string s)
    {
        // the index of the first vowel is stored. 
        int len = s.length();
        int index = -1;
        for (int i = 0; i < len; i++) {
            if (isVowel(s[i])) {
                index = i;
                break;
            }
        }
        // Pig Latin is possible only if vowels 
        // is present 
        if (index == -1)
            return "-1";

       // Take all characters after index (including 
        // index). Append all characters which are before 
       // index. Finally append "ay" 
       return s.substr(index) + s.substr(0, index) + "ay";
    }

};

bool Phrase::comparator(string a, string b)
{
    return a < b;
}
string Phrase::sortedWords(string unsortedWords) {
    // Used to split string around spaces. 
    vector<string> sortedWords;
    istringstream ss(unsortedWords);
    string finalSort;
    // Traverse through all words 
    do {
        // Read a word 
        string word;
        ss >> word;

        // Print the read word 
        sortedWords.push_back(word);

        // While there is more to read 
    } while (ss);


    sort(sortedWords.begin(), sortedWords.end());

    for (int c = 0; c < sortedWords.size(); c++)
        finalSort += sortedWords[c] + " ";

    return finalSort;
}


int main() {
    string input = "";   // user input for changing certain phrases
    
    cout << "\nPlease enter a valid sentence (with spaces): ";
    bool whiteSpacesOnly = std::all_of(input.begin(), input.end(), isspace); //used to determine if field is empty
    while (whiteSpacesOnly) {
        
        getline(cin, input);
        whiteSpacesOnly = std::all_of(input.begin(), input.end(), isspace);
    }

    Phrase inputObj1(input);  // this is the object on which methods operate

    cout << "Reversed Words In A Phrase: " << inputObj1.reversePhraseWords(inputObj1.phrase) << "\n";
    cout << "Words Sorted In Ascending Order: " << inputObj1.sortedWords(inputObj1.phrase) << "\n";
    cout << "Words encoded into Rot13: " << inputObj1.ROT13(inputObj1.phrase) << "\n";
    string str = inputObj1.pigLatin(inputObj1.phrase);

    if (str == "-1")
        cout << "No vowels found. Pig Latin not possible" << "\n";

    else
        cout << "Pig Latin version: " << str << "\n";

    int choice;

        bool gameOn = true;

        while (gameOn != false) {   //this is the menu with options

            cout << "\n*******************************\n";

            cout << " 1 - New Phrase.\n";

            cout << " 2 - Reverse Words.\n";

            cout << " 3 - Sort Words.\n";

            cout << " 4 - Rot13 Encoding.\n";

            cout << " 5 - Pig Latin Conversion.\n";

            cout << " 6 - Quit\n";

            cout << " Enter your choice and press return: ";

            cin >> choice;

            switch (choice)
            {
            case 1:

                cout << "\nNew Phrase String Manipulation\n";

                main();
                break;

            case 2:
                cout << "\nReversed Words In A New Phrase: " << inputObj1.reversePhraseWords(inputObj1.phrase) << "\n";
                break;

            case 3:
                cout << "\nWords Sorted In Ascending Order: " << inputObj1.sortedWords(inputObj1.phrase) << "\n";

                break;

            case 4:
                cout << "\nWords encoded into Rot13: " << inputObj1.ROT13(inputObj1.phrase) << "\n";

                break;
            case 5:

                if (str == "-1")
                    cout << "No vowels found. Pig Latin not possible" << "\n";

                else
                    cout << str << "\n";
                break;
            case 6:

                exit(0);

                break;
            default:

                cout << "Not a Valid Choice. \n";

                cout << "Choose again.\n";

                cin >> choice;

                break;
            }
        }



    return 0;

}