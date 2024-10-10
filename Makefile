CC = g++
CFLAGS = -Wall

TrieTest: Trie.o TrieTest.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

TrieTest.o: Trie.h Trie.cpp TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp

Trie.o: Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f TrieTest *.o