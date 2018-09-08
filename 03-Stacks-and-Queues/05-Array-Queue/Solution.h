//
// Created by hpf on 18-5-8.
//

class Solution {
public:
    std::vector <std::vector<int>> levelOrder(TreeNode *root) {
        std::vector <std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        ArrayQueue <std::pair<TreeNode *, int>> *queue = new ArrayQueue <std::pair<TreeNode *, int>>();
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
                queue->enqueue(std::make_pair(node->right, level + 1));
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
    class Array {
    private:
        T *data;
        int size;
        int capacity;

        void resize(int newCapacity) {
            T *newData = new T[newCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            data = newData;
            capacity = newCapacity;
        }

    public:
        Array(int capacity) {
            data = new T[capacity];
            size = 0;
            this->capacity = capacity;
        }

        Array() {
            data = new T[5];
            size = 0;
            capacity = 5;
        }

        int getCapacity() {
            return capacity;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void add(int index, T e) {
            assert(index >= 0 && index <= size);
            if (size == capacity) {
                resize(2 * capacity);
            }
            for (int i = size - 1; i >= index; --i) {
                data[i + 1] = data[i];
            }
            data[index] = e;
            size++;
        }

        void addFirst(T e) {
            add(0, e);
        }

        void addLast(T e) {
            add(size, e);
        }

        T get(int index) {
            assert(index >= 0 && index < size);
            return data[index];
        }

        void set(int index, T e) {
            assert(index >= 0 && index < size);
            data[index] = e;
        }

        bool contains(T e) {
            for (int i = 0; i < size; ++i) {
                if (data[i] == e) {
                    return true;
                }
            }
            return false;
        }

        int find(T e) {
            for (int i = 0; i < size; ++i) {
                if (data[i] == e) {
                    return i;
                }
            }
            return -1;
        }

        T remove(int index) {
            assert(index >= 0 && index < size);
            T ret = data[index];
            for (int i = index + 1; i < size; ++i) {
                data[i - 1] = data[i];
            }
            size--;
            if (size == capacity / 4 && capacity / 2 != 0) {
                resize(capacity / 2);
            }
            return ret;
        }

        T removeFirst() {
            return remove(0);
        }

        T removeLast() {
            return remove(size - 1);
        }

        void removeElement(T e) {
            int index = find(e);
            if (index != -1) {
                remove(index);
            }
        }

        /**
         * 打印数组的所有元素
         */
        void print() {
            std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
            toPrint();
            std::cout << std::endl;
        }

        void toPrint() {
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                std::cout << data[i];
                if (i != size - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]";
        }
    };

    template<class T>
    class ArrayQueue : public Queue<T> {
    public:
        ArrayQueue() {
            array = new Array<T>(10);
        }

        ArrayQueue(int capacity) {
            array = new Array<T>(capacity);
        }

        ~ArrayQueue() {
            delete[] array;
            array = nullptr;
        }

        int getSize() {
            return array->getSize();
        }

        T dequeue() {
            return array->removeFirst();
        }

        T getFront() {
            return array->getFirst();
        }

        void enqueue(T e) {
            array->addLast(e);
        }

        bool isEmpty() {
            return array->isEmpty();
        }

        /**
         * 打印数组的所有元素
         */
        void print() {
            std::cout << "Queue: size = " << array->getSize() << ", capacity = " << array->getCapacity() << std::endl;
            std::cout << "front ";
            array->toPrint();
            std::cout << " tail" << std::endl;
        }

    private:
        Array<T> *array;
    };
};
