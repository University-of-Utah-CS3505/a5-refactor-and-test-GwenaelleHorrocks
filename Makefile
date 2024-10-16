CC = g++ -std=c++2a
CFLAGS = -Wall
GOOGLETEST = ../googletest

test: Trie.o TrieTests.o 
	$(CC) $(CFLAGS) -o test TrieTests.o Trie.o -L$(GOOGLETEST)/lib/ -lgtest -lgtest_main -lpthread

TrieTests.o: Trie.h Trie.cpp TrieTests.cpp $(GOOGLETEST)/googletest/include/gtest/gtest.h
	$(CC) $(CFLAGS) -I$(GOOGLETEST)/googletest/include/ -c TrieTests.cpp

Trie.o: Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f TrieTest *.o