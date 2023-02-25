// Project1.cpp : 
// Your names  
// Eric Monestime  Amornrat Ajmo
#include <string>
#include <iostream>  
#include <sstream>
#include <vector>

using std::istringstream;
using std::string;
using std::vector;

/*
   You must complete the function funWithCallLetter.
   funWithCallLetter return the count of words in a string(s)

   The words are written using NATO Phonetic Alphabet: https://www.worldometers.info/languages/nato-phonetic-alphabet/.
   The words can be written with mixed cases.

   Word separator: 
	   Words can be separated by space(s), punctuation(.?!), new line ('\n').
	   If a word is finished by '-' and is followed by a new line, 
	   the next word is part of the last word on the previous line 
	   and count only as one(hyphenated).

	inputText: the input text you must processed
	outputText: the converted text to english. The word separator are transferred as-is 
				from the inputText. The outputText is always in lowercase.

	uniqueWord: count how many unique word was in the input text. 
	            The same word,with different case, count for one word(not case sensitive)

	Project1.cpp : you must implement the fcuntion funWithCallLetter, you cannot change its signature

	Project1.h    : the declaration of funWithCallLetter

	Project1Test  : unit tests to test countWords
	                you must add 4 additional unit tests(implemented in yourTests).  Each test must verify 
					additional logic that was not covered in the previous tests. Comment what specifically
					each of your additionnal tests is testing for.

	Grading       : 1 unit test for empty string         = 0
	                10 unit tests x 7 pts each           = 70
					4 additional unit tests x 5 pts each = 20 (you must complete them in yourTests)
					program structure                    = 10
					total                                = 100
	Your grade will be calculated on the last test your program manage to successfully execute, based on the 
	order in Project1Test.
	
	Program that do not compile will receive a grade of 0.

	Submission    : one submission per team
*/

 // This check if there's words or a charactor in the array

char check(string s, vector<string> arr, vector<char> letter) {
    for (int i = 0; i < arr.size(); i++) {
        if ((i == 0) && (s == arr[i] || s == "alpha")) {
            return letter[i];
        } 
        else if (s == arr[i]) {
            return letter[i];
        }
    }
    // Return the word or the charactor in the array
    return '*';
}

// This check a unique string in array.
bool uniqueCheck(string s, vector<string> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (s == arr[i]) {
            return false;
        }
    }
    // retrun true if it is unique
    return true;
}

unsigned int funWithCallLetter(const string &inputText, string &outputText, int &uniqueWord) {
    int wordCount = 0;
    uniqueWord = 0;
    outputText = "";
    // list all the nato word and charactor in the vector

    vector<string> words = {"alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india",
                            "juliett", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra",
                            "tango", "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu"};
    vector<char> letter = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                           's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Empty string                       
    string t2 = "";
    int i = 0;


    while (i < inputText.size()) {
        char a;
        char j = inputText[i];
        // Word separator, make a character 
        if(j== ' ' || j == '.' || j == '?' || j== '!' || j == '\n' || j == '-'){
            // We assign the value j to a
            a=j;
        }
        else{
            // make the input text to lower case, and assign to a
            a=char(tolower(inputText[i]));
        }
        // if not word separator, add the character in t2
        if (a != ' ' && a != '.' && a != '?' && a != '!' && a != '\n' && a != '-') {
            t2 += a;

            // We check t2 if it a word or a character, from the array.
            char res = check(t2, words, letter);

            // if it not either, we add the character to the ouputText, and made clear t2.
            if (res != '*') {
                outputText += res;
                t2 = "";
            }

        // if the next character '-' or '\n' we added to output, incrementing i and clear t2
        } else if (a == '-' && i + 1 < inputText.size() && inputText[i + 1] == '\n') {
            outputText += '-';
            outputText += "\n";
            i++;
            t2 = "";
        // if "a" is the Word sepetator, We check a if it a word or a charactor, from the array.
        } else if (a == ' ' || a == '.' || a == '?' || a == '!' || a == '\n' || a == '-') {
            char res = check(t2, words, letter);

            // if it not either, we add the character to the ouputText, and made clear t2.
            if (res != '*') {
                outputText += res;
                t2 = "";
            }
            // we add the value of "a" to the outputText 
            outputText +=a;
        }
        i++;
    }

    // if the word sepetator is not in array, we add it to the output, increment the wordcount and assign t2 to an empty string  
    char res = check(t2, words, letter);
    if (res != '*') {
        outputText += res;
        wordCount++;
        t2 = "";
    }
    
    // this part is for the Unique character 
    string word = "";
    vector<string> uniques;
    for (int i = 0; i < outputText.size(); i++) {

        // We check the output is not a word sepetator, we put the output in the string "word"    
        if (outputText[i] != ' ' && outputText[i] != '.' && outputText[i] != '?' && outputText[i] != '!' && outputText[i] != '\n' && outputText[i] != '-') {
            word += outputText[i];

        // if it a '-' or a '\n' we added the new charactor '-\n' to the new string 
        } else if (outputText[i] == '-' && i + 1 < outputText.size() && outputText[i + 1] == '\n') {
            word += '-\n';
            i++;

        // we check if there a Word sepetator, and if the word size is more than 1. We insert the "word" to uniques. increamting the uniqueWord
        } else if (outputText[i] == ' ' || outputText[i] == '.' || outputText[i] == '?' || outputText[i] == '!' || outputText[i] == '\n' || outputText[i] == '-') {
            if (word.size() > 1) {
                // we check if the word is unique or not
                if (uniqueCheck(word, uniques)) {
                    // if it a unique word, we insert to uniques
                    uniques.push_back(word);
                    // increment the uniqueWord
                    uniqueWord++;
                }
                // increase the word count
                wordCount++;
            }
            // assign the word to empty string
            word = "";
        }
    }
    // if the word is more than 1, we increase the wordCount, and insert the "word" to uniques. increamting the uniqueWord
    if (word.size() > 1) {
        wordCount++;
        // we check if the word is unique or not
        if (uniqueCheck(word, uniques)) {
            // if it a unique word, we insert to uniques
            uniques.push_back(word);
            // increment the uniqueWord
            uniqueWord++;
        }
    }
    return wordCount;
}