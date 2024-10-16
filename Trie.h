/* Austin Topham and Gwenaelle Horrocks - 10/15/24

   github: users: austinreed37 GwenaelleHorrocks
           repo: https://github.com/University-of-Utah-CS3505/a5-refactor-and-test-GwenaelleHorrocks

   Assignment A5: Refactoring and Testing

   This file is the .h file that declares all of the methods defined in Trie.cpp.
   This is also a refactored version of assignment 04 in which the Trie object stores everything
   in a map instead of an array of pointers. Methods includes rule of thirds, adding a word, checking
   to see if a word is inside the Trie, and retrieving all the words that start with a particular 
   prefix.
*/

#ifndef Trie_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class Trie {
    private:
    map<char, Trie> dictionary;
    bool validWord = false;

    public:

    /// @brief creates a new Trie object
    Trie();

    /// @brief destructs this trie object
    ~Trie();

    /// @brief copy constructor for Trie
    /// @param other the other Trie object to be copied from    
    Trie(const Trie& other);

    /// @brief implements the assignment operator using copy and swap
    /// @param other the other Trie object that this object will be assigned to
    /// @return this modified Trie object
    Trie& operator=(Trie other);

    /// @brief adds a Word to the dictionary
    /// @param word the word to be added
    void addWord(string word);

    /// @brief checks if given word is in the dictionary
    /// @param word the word to be checked
    /// @return true if the word is in the dictionary, false if not
    bool isWord(string word);

    /// @brief finds all words in the dictionary that start with the given prefix
    /// @param prefix the prefix all the words start with
    /// @return all words in the dictionary that start with the given prefix
    vector<string> allWordsStartingWithPrefix(string prefix);

    private:
    /// @brief private helper recursive method for allWordsStartingWithPrefix
    /// @param prefix the prefix the words start with
    /// @param words the words in the dictionary that start with the given prefix
    void prefixRecursive(string prefix, vector<string> &words);
};
#endif