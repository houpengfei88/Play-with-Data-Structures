//
// Created by hpf on 18-5-8.
//


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
    
private:
	template<typename T>
	class Queue {
	public:
		int getSize();

		bool isEmpty();

		void enqueue(T e);

		T dequeue();

		T getFront();
	};
	
	template<class T>
	class QNode {
	public:
		T e;
		QNode *next;

		QNode(T e, QNode *next) : e(e), next(next) {

		}

		QNode(T e) : e(e), next(nullptr) {

		}

		QNode() : next(nullptr) {

		}
	};

	template<class T>
	class LinkedListQueue : public Queue<T> {
	public:
		class Empty {
		};

		LinkedListQueue() {
		    head = nullptr;
		    tail = nullptr;
		    size = 0;
		}

		int getSize() {
		    return size;
		}

		bool isEmpty() {
		    return size == 0;
		}

		void enqueue(T e) {
		    if (tail == nullptr) {
		        tail = new QNode<T>(e);
		        head = tail;
		    } else {
		        tail->next = new QNode<T>(e);
		        tail = tail->next;
		    }
		    size++;
		}

		T dequeue() {
		    if (isEmpty()) {
		        throw Empty();
		    }
		    QNode<T> *retNode = head;
		    head = head->next;
		    retNode->next = nullptr;
		    if (head == nullptr) {
		        tail = nullptr;
		    }
		    size--;
		    return retNode->e;
		}

		T getFront() {
		    if (isEmpty()) {
		        throw Empty();
		    }
		    return head->e;
		}

		void print() {
		    QNode<T> *prev = head;
		    std::cout << "LinkListQueue: size = " << size << std::endl;
		    std::cout << "front ";
		    std::cout << "[";
		    while (prev != nullptr) {
		        std::cout << prev->e;
		        if (prev->next != nullptr) {
		            std::cout << ", ";
		        }
		        prev = prev->next;
		    }
		    std::cout << "] tail" << std::endl;
		}

	private:
		QNode<T> *head;
		QNode<T> *tail;
		int size;
	};
};
