/*
Austin Topham - Assignment 4
TrieTest tests the Trie class by testing the prefix method with two text files, provided by the user.
The first file should be a file of words, separated by lines, which will be added to the dictionary.
The second file should be a file of queries, separated by lines, which will be inputted into the function one-by-one.

It then tests the copy constructor and assignment operator functions.
*/
#include "Trie.h"
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;

int main(int argc, char **argv) {
    // make sure there are exactly three command line arguments
    if (argc != 3) {
        cerr << "Include three command line inputs: the executable, the file of words, and the file of querries. \n" <<
        "Example: ./trieTest wordsFile queriesFile" << endl;
        return 1;
    }

    // Open the words file
    ifstream wordsFile(argv[1]);
    if (!wordsFile) {
        cerr << "Error: Cannot open words file '" << argv[1] << "'" << endl;
        return 1;
    }

    // Open the queries file
    ifstream queriesFile(argv[2]);
    if (!queriesFile) {
        cerr << "Error: Cannot open queries file '" << argv[2] << "'" << endl;
        return 1;
    }

    // Create a Trie
    Trie dictionary;

    // Read words from the words file and add them to the Trie
    string word;
    while (getline(wordsFile, word)) {
        dictionary.addWord(word);
    }
    
    string query;

    // loop through queries and print prefix information 
    while (getline(queriesFile, query)) {

        cout << "Checking " << query << ":" << endl;

        bool isWord = dictionary.isWord(query);
        if (isWord) {
            cout << "Word found" << endl;
        } else {
            cout << "Word not found" << endl;
        }

        vector<string> prefixWords = dictionary.allWordsStartingWithPrefix(query);

        cout << "Words starting with prefix " << query << ": ";
        for (const string& w : prefixWords) {
            cout << w << " ";
        }
        cout << endl << endl;
    }

    cout << "Testing copy constructor and assignment operator functionality:" << endl;
    Trie fruits;

    fruits.addWord("orange");
    fruits.addWord("apple");
    fruits.addWord("pomegranate");
    fruits.addWord("");
    cout << "TESTING BLANK WORD: " << endl;
    cout << fruits.isWord("") << endl;

    Trie copyDict(fruits); // invoke copy constructor

    Trie assignmentDict;
    assignmentDict.addWord("strawberry");
    assignmentDict = fruits; // invoke assignment operator

    copyDict.addWord("banana");
    assignmentDict.addWord("blueberry");

    // At this point, fruits should have "apple", "orange", and "pomegranate":
    cout << "words in fruits: ";
    vector<string> fruitWords = fruits.allWordsStartingWithPrefix("");
    for (const string& word : fruitWords) {
        cout << word << " ";
    }
    cout << endl;

    // assignmentDict should have "apple", "blueberry", "orange", and "pomegranate":
    cout << "words in assignmentDict: ";
    vector<string> assignmentWords = assignmentDict.allWordsStartingWithPrefix("");
    for (const string& word : assignmentWords) {
        cout << word << " ";
    }
    cout << endl;

    cout << "words in copyDict: ";
    // copyDict should have "apple", "banana", "orange", and pomegranate":
    vector<string> copyWords = copyDict.allWordsStartingWithPrefix("");
    for (const string& word : copyWords) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}