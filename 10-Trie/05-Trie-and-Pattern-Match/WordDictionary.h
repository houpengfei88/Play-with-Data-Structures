/*
 * WordDictionary.h
 *
 *  Created on: 2018年6月5日
 *      Author: hpf
 */

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if (cur->next.find(c) == cur->next.end()) {
                cur->next.insert(std::pair<char, Node>(c, Node()));
            }
            cur = &cur->next.find(c)->second;
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(root, word, 0);
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
    
    bool match(Node *node, string word, int index) {
    	if (index == word.size()) {
    		return node->isWord;
    	}
    	char c = word.at(index);
    	if (c != '.') {
    		if (node->next.find(c) == node->next.end()) {
                return false;
            }
            return match(&node->next.find(c)->second, word, index + 1);
    	} else {
    		for(std::map<char, Node>::iterator iterator= node->next.begin();iterator != node->next.end();iterator++) {
             	if(match(&node->next.find(iterator->first)->second, word, index + 1)) {
             		return true;
             	}   
            }
            return false;
    	}    	
    }
};
