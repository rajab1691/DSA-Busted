# Trie / Prefix Tree
+ Trie is useful in efficient information retrieval data structures.
+ Trie is a tree that stores strings.

+ Why Trie? :-  
     1) With Trie, we can insert and find strings in O(L) time where L represent the length of a single word.
        This is obviously faster than BST. This is also faster than Hashing because of the ways it is implemented.
        We do not need to compute any hash function. No collision handling is required (like we do in open addressing and separate chaining)
        
     2) Another advantage of Trie is, we can easily print all words in alphabetical order which is not easily possible with hashing.
     3) We can efficiently do prefix search (or auto-complete) with Trie.

+ Issues with Trie :- 
    1) The main disadvantage of tries is that they need a lot of memory for storing the strings.

- [Little more about Trie](https://leetcode.com/discuss/general-discussion/1066206/introduction-to-trie)
