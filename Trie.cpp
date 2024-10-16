/* Austin Topham and Gwenaelle Horrocks - Assignment 5
   10/15/24

   github: users: austinreed37 GwenaelleHorrocks
           repo: https://github.com/University-of-Utah-CS3505/a5-refactor-and-test-GwenaelleHorrocks

   Assignment A5: Refactoring and Testing

   This file is the .cpp file that defines all of the methods declared in Trie.h.
   This is also a refactored version of assignment 04 in which the Trie object stores everything
   in a map instead of an array of pointers. Methods includes rule of thirds, adding a word, checking
   to see if a word is inside the Trie, and retrieving all the words that start with a particular 
   prefix.
*/

#include "Trie.h"
#include <string>
#include <array>
using std::swap;

Trie::Trie() {}

Trie::~Trie() {
}

Trie::Trie(const Trie &other) {
    // copy data memebers of other Trie object
    validWord = other.validWord;
    for (auto pair : other.dictionary) {
        dictionary[pair.first] = pair.second;
    }
}

Trie& Trie::operator=(Trie other) {
    swap(validWord, other.validWord);
    swap(dictionary, other.dictionary);
    return *this;
}

void Trie::addWord(string word) {
    
    // when word is empty, an empty string has been inputted and the function returns
    if (word.length() == 0) {
        return;
    }

    char letter = word[0];
    // make a new Trie and add it to map if map doesn't contain letter
    if (!(dictionary.contains(letter))) {
        Trie newTrie;
        dictionary[letter] = newTrie;
    }

    // when word has just one character, this character is marked as the end of a valid word and the function returns
    if (word.length() == 1) {
        dictionary[letter].validWord = true;
        return;
    }

    // recursively call addWord with word minus the first letter
    dictionary[letter].addWord(word.substr(1));
}

bool Trie::isWord(string word) {
    // when word is empty, the end of the word has been reached and validWord is returned. Since empty strings are never
    // added, this will return false for an empty word.
    if (word.length() == 0) {
        return validWord;
    }

    char letter = word[0];
    if (letter < 'a' || letter > 'z') {
        return false;
    }

    if (!(dictionary.contains(letter))) {
        return false;
    }

    // recursively call isWord with word minus the first letter
    return dictionary[letter].isWord(word.substr(1));
}

vector<string> Trie::allWordsStartingWithPrefix(string prefix) {
    vector<string> prefixWords;
    Trie* currentTrie = this;

    // iteratively navigate down the trie to the end of the prefix
    for (size_t i = 0; i < prefix.length(); i++) {
        char letter = prefix[i];

        if (letter < 'a' || letter > 'z') {
            return prefixWords;
        }

        if (!currentTrie->dictionary.contains(letter)) {
            return prefixWords;
        }

        currentTrie = &currentTrie->dictionary[letter];
    }
 
    // at this point, currentTrie represents the node corresponding to the prefix
    // collect all words starting from currentTrie
    currentTrie->prefixRecursive(prefix, prefixWords);
    return prefixWords;
}

void Trie::prefixRecursive(string prefix, vector<string>& words) {
    // add current word to the vector if it is marked as a valid word
    if (validWord) {
        words.push_back(prefix);
    }

    // depth-first recursion into all words that start with prefix, adding them to the vector if they are valid words
    for (auto& pair : dictionary) {
        char currentLetter = pair.first;
        string newPrefix = prefix + currentLetter;
        dictionary[pair.first].prefixRecursive(newPrefix, words);
    }
}