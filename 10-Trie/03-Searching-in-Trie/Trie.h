/*
 * Trie.h
 *
 *  Created on: 2018年6月5日
 *      Author: hpf
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <map>
#include <string>

class Trie {
private:
    class Node {
    public:
        bool isWord;
        std::map<char, Node> next;

        Node(bool isWord) {
            this->isWord = isWord;
        }

        Node() : isWord(false), next() {}
    };

    Node *root;
    int size;
public:
    Trie() {
        root = new Node();
        size = 0;
    }

    int getSize() {
        return size;
    }

    void add(std::string word) {
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
            size++;
        }
    }

    bool contains(std::string word) {
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
};

#endif /* TRIE_H_ */
