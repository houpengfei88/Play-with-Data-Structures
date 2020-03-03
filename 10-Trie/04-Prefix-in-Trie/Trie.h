/*
 * Trie.h
 *
 *  Created on: 2018年6月5日
 *      Author: hpf
 */

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if (cur->next.find(c) == cur->next.end()) {
                cur->next.insert(std::pair<char, Node>(c, Node()));
            }
            cur = &cur->next.find(c)->second;
        }

        if (!cur->isWord) {
            cur->isWord = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if (cur->next.find(c) == cur->next.end()) {
                return false;
            }
            cur = &cur->next.find(c)->second;
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix.at(i);
            if (cur->next.find(c) == cur->next.end()) {
                return false;
            }
            cur = &cur->next.find(c)->second;
        }
        return true;
    }
private:
    class Node {
    public:
        bool isWord;
        std::map<char, Node> next;

        Node() {
            isWord = false;
        }
    };

    Node *root;
};
