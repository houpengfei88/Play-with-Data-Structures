/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    std::vector <std::vector<int>> levelOrder(TreeNode *root) {
        std::vector <std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        LoopQueue <pair<TreeNode *, int>> *queue = new LoopQueue <pair<TreeNode *, int>>();
        queue->enqueue(make_pair(root, 0));

        while (!queue->isEmpty()) {
            TreeNode *node = queue->getFront().first;
            int level = queue->getFront().second;
            queue->dequeue();

            if (level == res.size()) {
                res.push_back(std::vector<int>());
            }
            assert(level < res.size() && level >= 0);
            
            res[level].push_back(node->val);
            if (node->left) {
                queue->enqueue(std::make_pair(node->left, level + 1));
            }
            if (node->right) {
                queue->enqueue(std::make_pair(node->right, level + 1));
            }
        }
        return res;
    }

private:
    template<typename T>
    class Queue {
    public:
        virtual int getSize() = 0;

        virtual bool isEmpty() = 0;

        virtual void enqueue(T e) = 0;

        virtual T dequeue() = 0;

        virtual T getFront() = 0;
    };

    template<typename T>
    class LoopQueue : public Queue<T> {
    public:

        LoopQueue() {
            data = new T[10];
            front = 0;
            tail = 0;
            capacity = 10;
        }

        LoopQueue(int capacity) {
            data = new T[capacity + 1];
            front = 0;
            tail = 0;
            this->capacity = capacity;
        }

        ~LoopQueue() {
            delete[] data;
            data = nullptr;
        }

        bool isEmpty() {
            return front == tail;
        }

        int getSize() {
            return (tail + capacity - front) % capacity;
        }

        int getCapacity() {
            return capacity;
        }

        void enqueue(T e) {
            if ((tail + 1) % capacity == front) {
                resize(capacity * 2);
            }
            data[tail] = e;
            tail = (tail + 1) % capacity;
        }

        T getFront() {
            assert(front != tail);
            return data[front];
        }

        T dequeue() {
            assert(front != tail);
            T ret = data[front];
            front = (front + 1) % capacity;
            if (getSize() == capacity / 4 && capacity / 2 != 0) {
                resize(capacity / 2);
            }
            return ret;
        }

        /**
         * 打印数组的所有元素
         */
        void print() {
            std::cout << "LoopQueue: size = " << getSize() << ", capacity = " << capacity << std::endl;
            std::cout << "front [";
            for (int i = front; i != tail; i = (i + 1) % capacity) {
                std::cout << data[i];
                if ((i + 1) % capacity != tail) {
                    std::cout << ", ";
                }
            }
            std::cout << "] tail" << std::endl;
        }

    private:
        T *data;
        int front, tail;
        int capacity;

        // 将数组空间的容量变成newCapacity大小
        void resize(int newCapacity) {
            T *newData = new T[newCapacity + 1];
            for (int i = 0; i < getSize(); ++i) {
                newData[i] = data[(i + front) % capacity];
            }
            data = newData;
            tail = getSize();
            front = 0;
            capacity = newCapacity;
            newData = nullptr;
            delete[] newData;
        }
    };
};
