//
// Created by hpf on 18-5-14.
//

class Solution {
public:
    static vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        BSTMap<int, int> *record = new BSTMap<int, int>();
        for (int num : nums1) {
            if (!record->contains(num)) {
                record->add(num, 1);
            } else {
                record->set(num, *(record->get(num)) + 1);
            }
        }
        vector<int> resultMap;
        for (int num : nums2) {
            if (record->contains(num)) {
                resultMap.push_back(num);
                record->set(num, *(record->get(num)) - 1);
                if (*(record->get(num)) == 0) {
                    record->remove(num);
                }
            }
        }
        return resultMap;
    }

private:
    template<typename Key, typename Value>
    class Map {
        void add(Key key, Value value);

        Value remove(Key key);

        bool contains(Key key);

        Value get(Key key);

        void set(Key key, Value value);

        int getSize();

        bool isEmpty();
    };

    template<typename Key, typename Value>
    class BSTMap : public Map<Key, Value> {
    private:
        struct Node {
            Key key;
            Value value;
            Node *left;
            Node *right;

            Node(Key key, Value value) {
                this->key = key;
                this->value = value;
                this->left = this->right = nullptr;
            }

            Node(Node *node) {
                this->key = node->key;
                this->value = node->value;
                this->left = node->left;
                this->right = node->right;
            }

        };

        Node *root;
        int size;

    public:

        BSTMap() {
            root = nullptr;
            size = 0;
        }

        ~BSTMap() {
            destroy(root);
        }

        int getSize() {
            return size;
        }

        int isEmpty() {
            return size == 0;
        }

        void add(Key key, Value value) {
            root = add(root, key, value);
        }

        bool contains(Key key) {
            return getNode(root, key) != nullptr;
        }

        Value *get(Key key) {
            Node *node = getNode(root, key);
            return node == nullptr ? nullptr : &(node->value);
        }

        void set(Key key, Value newValue) {
            Node *node = getNode(root, key);
            if (node != nullptr) {
                node->value = newValue;
            }
        }

        // 从二叉树中删除键值为key的节点
        Value *remove(Key key) {
            Node *node = getNode(root, key);
            if (node != nullptr) {
                root = remove(root, key);
                return &(node->value);
            }
            return nullptr;
        }

    private:

        // 向以node为根的二叉搜索树中,插入节点(key, value)
        // 返回插入新节点后的二叉搜索树的根
        Node *add(Node *node, Key key, Value value) {
            if (node == nullptr) {
                size++;
                return new Node(key, value);
            }
            if (key == node->key) {
                node->value = value;
            } else if (key < node->key) {
                node->left = add(node->left, key, value);
            } else {
                node->right = add(node->right, key, value);
            }
            return node;
        }

        // 在以node为根的二叉搜索树中查找key所对应的Node
        Node *getNode(Node *node, Key key) {
            if (node == nullptr) {
                return nullptr;
            }
            if (key == node->key) {
                return node;
            } else if (key < node->key) {
                return getNode(node->left, key);
            } else {
                return getNode(node->right, key);
            }
        }

        void destroy(Node *node) {
            if (node != nullptr) {
                destroy(node->left);
                destroy(node->right);
                delete node;
                size--;
            }
        }

        // 在以node为根的二叉搜索树中,返回最小键值的节点
        Node *minimum(Node *node) {
            if (node->left == nullptr)
                return node;
            return minimum(node->left);
        }

        // 在以node为根的二叉搜索树中,返回最大键值的节点
        Node *maximum(Node *node) {
            if (node->right == nullptr)
                return node;
            return maximum(node->right);
        }

        // 删除掉以node为根的二分搜索树中的最小节点
        // 返回删除节点后新的二分搜索树的根
        Node *removeMin(Node *node) {
            if (node->left == nullptr) {
                Node *rightNode = node->right;
                delete node;
                size--;
                return rightNode;
            }

            node->left = removeMin(node->left);
            return node;
        }

        // 删除掉以node为根的二分搜索树中的最大节点
        // 返回删除节点后新的二分搜索树的根
        Node *removeMax(Node *node) {
            if (node->right == nullptr) {
                Node *leftNode = node->left;
                delete node;
                size--;
                return leftNode;
            }

            node->right = removeMax(node->right);
            return node;
        }

        // 删除掉以node为根的二分搜索树中键值为key的节点
        // 返回删除节点后新的二分搜索树的根
        Node *remove(Node *node, Key key) {
            if (node == nullptr) {
                return nullptr;
            }
            if (key < node->key) {
                node->left = remove(node->left, key);
                return node;
            } else if (key > node->key) {
                node->right = remove(node->right, key);
                return node;
            } else {
                if (node->left == nullptr) {
                    Node *rightNode = node->right;
                    delete node;
                    size--;
                    return rightNode;
                }

                if (node->right == nullptr) {
                    Node *leftNode = node->left;
                    delete node;
                    size--;
                    return leftNode;
                }

                Node *successor = new Node(minimum(node->right));
                //Node *precursor = new Node(maximum(node->right));
                size++;

                successor->right = removeMin(node->right);
                successor->left = node->left;
                //precursor->left = removeMax(node->left);
                //precursor->right = node->right;

                delete node;
                size--;

                return successor;
                //return precursor;
            }
        }

    };
};
