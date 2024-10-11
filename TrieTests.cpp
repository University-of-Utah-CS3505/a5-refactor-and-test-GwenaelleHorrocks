#include "Trie.h"
#include <vector>
#include <gtest/gtest.h>

// using namespace googletest;

// basic isWord
TEST(TrieTests, basicIsWord) {
    Trie trie;
    trie.addWord("hello");
    ASSERT_TRUE(trie.isWord("hello"));
};

TEST(TrieTests, addEmpty) {
    Trie trie;
    trie.addWord("");
    ASSERT_FALSE(trie.isWord(""));
};

TEST(TrieTests, returnEmptyPrefix) {
    Trie trie;    
    trie.addWord("hello");
    trie.addWord("blueberry");
    trie.addWord("apple");

    vector<std::string> vector;
    vector.push_back("apple");
    vector.push_back("blueberry");
    vector.push_back("hello");

    ASSERT_EQ(vector, trie.allWordsStartingWithPrefix(""));
};

TEST(TrieTests, returnEmpty) {
    Trie trie;   
    vector<std::string> vector = trie.allWordsStartingWithPrefix(""); 

    ASSERT_TRUE(vector.empty());
};

TEST(TrieTests, isWordCapital) {
    Trie trie;

    trie.addWord("hello");

    ASSERT_FALSE(trie.isWord("Hello"));
}




