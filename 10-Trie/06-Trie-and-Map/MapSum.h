/*
 * MapSum.h
 *
 *  Created on: 2018年6月5日
 *      Author: hpf
 */

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node *cur = root;
        for (int i = 0; i < key.size(); ++i) {
            char c = key.at(i);
            if (cur->next.find(c) == cur->next.end()) {
                cur->next.insert(std::pair<char, Node>(c, Node()));
            }
            cur = &cur->next.find(c)->second;
        }
        cur->value = val;
    }
    
    int sum(string prefix) {
        Node *cur = root;
        for (int i = 0; i < prefix.size(); i++) {
        	char c = prefix.at(i);
        	if (cur->next.find(c) == cur->next.end()) {
        		return 0;
        	}
        	cur = &cur->next.find(c)->second;
        }
        return sum(cur);
    }
private:
    class Node {
    public:
        int value;
        std::map<char, Node> next;

        Node() {
            value = 0;
        }
    };

    Node *root;
    
    int sum(Node *node) {
    	int res = node->value;
    	for(std::map<char, Node>::iterator iterator= node->next.begin();iterator != node->next.end();iterator++){
        	res += sum(&node->next.find(iterator->first)->second);  
        }
        return res;
    }
};
