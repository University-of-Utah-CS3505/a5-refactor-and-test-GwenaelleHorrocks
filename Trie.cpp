/* Austin Topham - Assignment 4
*/

#include "Trie.h"
#include <string>
#include <array>
using std::swap;

Trie::Trie() {}

Trie::~Trie() {
    // for (int i = 0; i < 26; i++) {
    //     if (dictionary[i]) {
    //         //recursively calls the destructor on every initialized node in the trie
    //         delete dictionary[i];
    //     }
    // }
}

Trie::Trie(const Trie &other) {
    // copy data memebers of other Trie object
    validWord = other.validWord;
    for (auto pair : other.dictionary) {
        dictionary[pair.first] = pair.second; // Assuming dictionary is a map
    }
}

Trie& Trie::operator=(Trie other) {
    swap(validWord, other.validWord);
    swap(dictionary, other.dictionary);
    return *this;
}

void Trie::addWord(string word) {
    
    // when word is empty, the end of the word has been reached and the current trie can be marked as a valid word
    if (word.length() == 0) {
        return;
    }

    // get the index of the first letter in word, set nextTrie equal to the trie in this trie's index
    char letter = word[0];
    //Trie* nextTrie = this->dictionary[letter];

    if (!(dictionary.contains(letter))) {
        Trie newTrie;
        dictionary[letter] = newTrie;
    }

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

    // get the index of the first letter in word, set nextTrie equal to the trie in this trie's index
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
    Trie currentTrie = *this;
    Trie nextTrie;

    // iteratively navigate down the trie to the end of the prefix
    for (size_t i = 0; i < prefix.length(); i++) {
        char letter = prefix[i];
        //nextTrie = currentTrie->dictionary[letter];

        if (letter < 'a' || letter > 'z') {
            std::cout << "wrong letter" << std::endl;
            return prefixWords;
        }

        std::cout << "how many" << std::endl;

        if (!currentTrie.dictionary.contains(letter)) {
            std::cout << "ended early" << std::endl;
            return prefixWords;
        }

        currentTrie = currentTrie.dictionary[letter];
    }
 
    // at this point, currentTrie represents the node corresponding to the prefix
    // collect all words starting from currentTrie
    currentTrie.prefixRecursive(prefix, prefixWords);

    return prefixWords;
}

void Trie::prefixRecursive(string prefix, vector<string>& words) {
    std::cout << "recursive" << std::endl;
    // add current word to the vector if it is marked as a valid word
    if (validWord) {
        std::cout << "valid" << std::endl;
        words.push_back(prefix);
    }

    // depth-first recursion into all words that start with prefix, adding them to the vector if they are valid words
    for (auto& pair : dictionary) {
        std::cout << "for loop" << std::endl;
        char currentLetter = pair.first;
        string newPrefix = prefix + currentLetter;
        dictionary[pair.first].prefixRecursive(newPrefix, words);
    }
}