class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string> &words) {
        std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                          ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                                          ".--", "-..-", "-.--", "--.."};
        RBTree <std::string, int> bstSet;
        for (const std::string &word : words) {
            std::cout << '"' << word << '"' << " -> ";
            std::string code = "";
            for (char c : word) {
                code += morse[c - 'a'];
            }
            std::cout << '"' << code << '"' << std::endl;
            if (!bstSet.contains(code)) {
                bstSet.add(code, 1);
            }
        }
        return bstSet.getSize();
    }
private:
	template<typename Key, typename Value>
	class RBTree {
	private:
		static const bool RED = true;
		static const bool BLACK = false;

		struct Node {
		    Key key;
		    Value value;
		    Node *left;
		    Node *right;
		    bool color;

		    Node(Key key, Value value) {
		        this->key = key;
		        this->value = value;
		        this->left = this->right = nullptr;
		        color = RED;
		    }

		    Node(Node *node) {
		        this->key = node->key;
		        this->value = node->value;
		        this->left = node->left;
		        this->right = node->right;
		        this->color = node->color;
		    }
		};

		Node *root;
		int size;

	public:

		RBTree() {
		    root = nullptr;
		    size = 0;
		}

		~RBTree() {
		    destroy(root);
		}

		int getSize() {
		    return size;
		}

		int isEmpty() {
		    return size == 0;
		}

		bool isRed(Node *node) {
		    if (node == nullptr) {
		        return BLACK;
		    }
		    return node->color;
		}

		void add(Key key, Value value) {
		    root = add(root, key, value);
		    root->color = BLACK;
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

		    if (isRed(node->right) && !isRed(node->left)) {
		        node = leftRotate(node);
		    }

		    if (isRed(node->left) && isRed(node->left->left)) {
		        node = rightRotate(node);
		    }

		    if (isRed(node->left) && isRed(node->right)) {
		        flipColors(node);
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

		Node *leftRotate(Node *node) {
		    Node *x = node->right;
		    node->right = x->left;
		    x->left = node;

		    x->color = node->color;
		    node->color = RED;

		    return x;
		}

		Node *rightRotate(Node *node) {
		    Node *x = node->left;
		    node->left = x->right;
		    x->right = node;

		    x->color = node->color;
		    node->color = RED;

		    return x;
		}

		void flipColors(Node *node) {
		    node->color = RED;
		    node->left->color = BLACK;
		    node->right->color = BLACK;
		}
	};
};
