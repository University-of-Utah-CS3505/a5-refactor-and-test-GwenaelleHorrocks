#include "Trie.h"
#include <vector>
#include <gtest/gtest.h>

// basic isWord
TEST(TrieTests, basicIsWord) {
    Trie trie;
    trie.addWord("hello");
    ASSERT_TRUE(trie.isWord("hello"));
};

TEST(TrieTests, destructorOnTriePointer) {
    Trie* trie = new Trie();
    trie -> addWord("hello");
    delete trie;
};

TEST(TrieTests, addEmpty) {
    Trie trie;
    trie.addWord("");
    ASSERT_FALSE(trie.isWord(""));
};

TEST(TrieTests, checkEmptyIsWord) {
    Trie trie;
    trie.addWord("cat");
    ASSERT_FALSE(trie.isWord(""));
};

TEST(TrieTests, checkEmptyTrie) {
    Trie trie;
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

TEST(TrieTests, returnLongPrefixList) {
    Trie trie;    
    trie.addWord("applesauce");
    trie.addWord("a");
    trie.addWord("apple");
    trie.addWord("aubergine");
    trie.addWord("away");
    trie.addWord("app");    
    trie.addWord("angry");
    trie.addWord("austin");
    trie.addWord("awesome");
    trie.addWord("agwen");
    trie.addWord("abba");
    trie.addWord("and");

    vector<std::string> vector;
    vector.push_back("a");
    vector.push_back("abba");
    vector.push_back("agwen");
    vector.push_back("and");
    vector.push_back("angry");
    vector.push_back("app");
    vector.push_back("apple");
    vector.push_back("applesauce");
    vector.push_back("aubergine");
    vector.push_back("austin");
    vector.push_back("away");
    vector.push_back("awesome");

    ASSERT_EQ(vector, trie.allWordsStartingWithPrefix("a"));
};

TEST(TrieTests, returnCaptitalPrefixList) {
    Trie trie;    
    trie.addWord("applesauce");
    trie.addWord("a");
    trie.addWord("apple");
    trie.addWord("aubergine");
    trie.addWord("away");
    trie.addWord("app");    
    trie.addWord("angry");
    trie.addWord("austin");
    trie.addWord("awesome");
    trie.addWord("agwen");
    trie.addWord("abba");
    trie.addWord("and");

    vector<std::string> vector;

    ASSERT_EQ(vector, trie.allWordsStartingWithPrefix("A"));
};

TEST(TrieTests, returnPrefixWord) {
    Trie trie;    
    trie.addWord("hello");
    trie.addWord("blueberry");
    trie.addWord("apple");

    vector<std::string> vector;
    vector.push_back("apple");

    ASSERT_EQ(vector, trie.allWordsStartingWithPrefix("apple"));
};

TEST(TrieTests, basicReturnPrefix) {
    Trie trie;    
    trie.addWord("hello");
    trie.addWord("blueberry");
    trie.addWord("apple");
    trie.addWord("applepie");
    trie.addWord("applesquash");

    vector<std::string> vectorExpected;
    vectorExpected.push_back("apple");
    vectorExpected.push_back("applepie");
    vectorExpected.push_back("applesquash");

    ASSERT_EQ(vectorExpected, trie.allWordsStartingWithPrefix("apple"));
};

TEST(TrieTests, returnEmpty) {
    Trie trie;   
    vector<std::string> vector = trie.allWordsStartingWithPrefix(""); 

    ASSERT_TRUE(vector.empty());
};

TEST(TrieTests, returnNonExistentPrefix) {
    Trie trie; 
    trie.addWord("cat");
    trie.addWord("dog");
    trie.addWord("rat");
    vector<std::string> vector = trie.allWordsStartingWithPrefix("f"); 

    ASSERT_TRUE(vector.empty());
};


TEST(TrieTests, isWordCapital) {
    Trie trie;
    trie.addWord("hello");

    ASSERT_FALSE(trie.isWord("Hello"));
}

TEST(TrieTests, copyConstructorEquals){
    Trie trie;
    trie.addWord("cat");
    trie.addWord("dog");
    trie.addWord("rat");
    Trie copy = trie;

    vector<std::string> vectorOriginal = trie.allWordsStartingWithPrefix("");
    vector<std::string> vectorCopy = copy.allWordsStartingWithPrefix("");

    ASSERT_EQ(vectorOriginal, vectorCopy);
}

TEST(TrieTests, copyConstructorNotDependent){
    Trie trie;
    trie.addWord("cat");
    trie.addWord("dog");
    trie.addWord("rat");
    Trie copy = trie;
    copy.addWord("penguin");

    vector<std::string> vectorOriginal = trie.allWordsStartingWithPrefix("");
    vector<std::string> vectorCopy = copy.allWordsStartingWithPrefix("");

    ASSERT_NE(vectorOriginal, vectorCopy);
}

TEST(TrieTests, copyConstructorEmpty){
    Trie trie;
    Trie copy = trie;

    vector<std::string> vectorOriginal = trie.allWordsStartingWithPrefix("");
    vector<std::string> vectorCopy = copy.allWordsStartingWithPrefix("");

    ASSERT_EQ(vectorOriginal, vectorCopy);
}

TEST(TrieTests, assignmentOperatorEquals){
    Trie trie;
    trie.addWord("cat");
    trie.addWord("dog");
    trie.addWord("rat");
    Trie copy;
    copy = trie;

    vector<std::string> vectorOriginal = trie.allWordsStartingWithPrefix("");
    vector<std::string> vectorCopy = copy.allWordsStartingWithPrefix("");

    ASSERT_EQ(vectorOriginal, vectorCopy);
}

TEST(TrieTests, assignmentOperatorNotDependent){
    Trie trie;
    trie.addWord("cat");
    trie.addWord("dog");
    trie.addWord("rat");
    Trie copy;
    copy = trie;
    copy.addWord("penguin");

    vector<std::string> vectorOriginal = trie.allWordsStartingWithPrefix("");
    vector<std::string> vectorCopy = copy.allWordsStartingWithPrefix("");

    ASSERT_NE(vectorOriginal, vectorCopy);
}

TEST(TrieTests, assignmentOperatorEmpty){
    Trie trie;
    Trie copy;
    copy = trie;

    vector<std::string> vectorOriginal = trie.allWordsStartingWithPrefix("");
    vector<std::string> vectorCopy = copy.allWordsStartingWithPrefix("");

    ASSERT_EQ(vectorOriginal, vectorCopy);
}



