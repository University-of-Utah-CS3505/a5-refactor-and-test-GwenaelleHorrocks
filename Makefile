CC = g++
CFLAGS = -Wall
GOOGLETEST = ../googletest/

tests: Trie.o TrieTests.o
	$(CC) $(CFLAGS) -o tests TrieTests.o Trie.o

TrieTests.o: Trie.h Trie.cpp TrieTests.cpp
	$(CC) $(CFLAGS) -c TrieTests.cpp

Trie.o: Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f TrieTest *.o