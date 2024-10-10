/* Austin Topham - Assignment 4
*/

#include "Trie.h"
#include <string>
#include <array>
using std::swap;

Trie::Trie() {}

Trie::~Trie() {
    for (int i = 0; i < 26; i++) {
        if (alphabet[i]) {
            //recursively calls the destructor on every initialized node in the trie
            delete alphabet[i];
        }
    }
}

Trie::Trie(const Trie &other) {
    // copy data memebers of other Trie object
    validWord = other.validWord;
    for (int i = 0; i < 26; i++) {
        if (other.alphabet[i]) {
            alphabet[i] = new Trie(*other.alphabet[i]);
        }
        else {
            alphabet[i] = nullptr;
        }
    }
}

Trie& Trie::operator=(Trie other) {
    swap(validWord, other.validWord);
    for (int i = 0; i < 26; ++i) {
        swap(alphabet[i], other.alphabet[i]);
    }
    return *this;
}

void Trie::addWord(string word) {
    
    // when word is empty, the end of the word has been reached and the current trie can be marked as a valid word
    if (word.length() == 0) {
        return;
    }

    // get the index of the first letter in word, set nextTrie equal to the trie in this trie's index
    int index = word[0] - 'a';
    Trie* nextTrie = this->alphabet[index];

    if (!nextTrie) {
        nextTrie = new Trie();
        this->alphabet[index] = nextTrie;
    }

    if (word.length() == 1) {
        alphabet[index]->validWord = true;
        return;
    }

    // recursively call addWord with word minus the first letter
    nextTrie->addWord(word.substr(1));
}

bool Trie::isWord(string word) {
    // when word is empty, the end of the word has been reached and validWord is returned. Since empty strings are never
    // added, this will return false for an empty word.
    if (word.length() == 0) {
        return this->validWord;
    }

    // get the index of the first letter in word, set nextTrie equal to the trie in this trie's index
    int index = word[0] - 'a';
    Trie* nextTrie = this->alphabet[index];

    if (!nextTrie) {
        return false;
    }

    // recursively call isWord with word minus the first letter
    return nextTrie->isWord(word.substr(1));
}

vector<string> Trie::allWordsStartingWithPrefix(string prefix) {
    vector<string> prefixWords;
    Trie* currentTrie = this;
    Trie* nextTrie;

    // iteratively navigate down the trie to the end of the prefix
    for (size_t i = 0; i < prefix.length(); i++) {
        int prefixIndex = prefix[i] - 'a';
        nextTrie = currentTrie->alphabet[prefixIndex];

        if (prefixIndex < 0 || prefixIndex >= 26) {
            return prefixWords;
        }

        if (!nextTrie) {
            return prefixWords;
        }

        currentTrie = nextTrie;
    }

    // at this point, currentTrie represents the node corresponding to the prefix
    // collect all words starting from currentTrie
    currentTrie->prefixRecursive(prefix, prefixWords);

    return prefixWords;
}

void Trie::prefixRecursive(string prefix, vector<string>& words) {
    // add current word to the vector if it is marked as a valid word
    if (this->validWord) {
        words.push_back(prefix);
    }

    // depth-first recursion into all words that start with prefix, adding them to the vector if they are valid words
    for (int i = 0; i < 26; i++) {
        if (this->alphabet[i]) {
            char currentLetter = 'a' + i;
            string newPrefix = prefix + currentLetter;
            this->alphabet[i]->prefixRecursive(newPrefix, words);
        }
    }
}