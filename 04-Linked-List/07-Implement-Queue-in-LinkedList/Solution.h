//
// Created by hpf on 18-5-8.
//

#include "LinkedListQueue.h"
#include <list>
#include <vector>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int e) : val(e), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        LinkedListQueue<std::pair<TreeNode *, int>> *queue = new LinkedListQueue<std::pair<TreeNode *, int>>();
        queue->enqueue(std::make_pair(root, 0));
        while (!queue->isEmpty()) {
            TreeNode *node = queue->getFront().first;
            int level = queue->getFront().second;
            queue->dequeue();
            if (level == res.size()) {
                res.push_back(std::vector<int>());
            }
            assert(level < res.size());
            res[level].push_back(node->val);
            if (node->left) {
                queue->enqueue(std::make_pair(node->left, level + 1));
            }
            if (node->right) {
                queue->enqueue(std::make_pair(node->right,level +1));
            }
        }
        return res;
    }

};
