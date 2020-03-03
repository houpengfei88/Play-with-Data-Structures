//
// Created by hpf on 18-5-8.
//

// Leetcode 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// 二叉树的层序遍历
//
// 二叉树的层序遍历是一个典型的可以借助队列解决的问题。
// 该代码主要用于使用Leetcode上的问题测试我们的ArrayQueue。
// 对于二叉树的层序遍历，这个课程后续会讲到。
// 届时，同学们也可以再回头看这个代码。
// 不过到时，大家应该已经学会自己编写二叉树的层序遍历啦:)

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
        virtual int getSize() = 0;

        virtual bool isEmpty() = 0;

        virtual void enqueue(T e) = 0;

        virtual T dequeue() = 0;

        virtual T getFront() = 0;
    };

    template<typename T>
    class Array {
    public:
        // 构造函数，传入数组的容量capacity构造Array
        Array(int capacity) {
            data = new T[capacity];
            size = 0;
            this->capacity = capacity;
        }

        // 无参数的构造函数，默认数组的容量capacity=10
        Array() {
            data = new T[5];
            size = 0;
            capacity = 5;
        }

        // 获取数组的容量
        int getCapacity() {
            return capacity;
        }

        // 获取数组中的元素个数
        int getSize() {
            return size;
        }

        // 返回数组是否为空
        bool isEmpty() {
            return size == 0;
        }

        // 在index索引的位置插入一个新元素e
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

        // 在所有元素前添加一个新元素
        void addFirst(T e) {
            add(0, e);
        }

        // 向所有元素后添加一个新元素
        void addLast(T e) {
            add(size, e);
        }

        // 获取index索引位置的元素
        T get(int index) {
            assert(index >= 0 && index < size);
            return data[index];
        }

        // 获取索引位置为0的元素
        T getFirst() {
            return get(0);
        }

        // 获取最后索引位置的元素
        T getLast() {
            return get(size - 1);
        }

        // 修改index索引位置的元素为e
        void set(int index, T e) {
            assert(index >= 0 && index < size);
            data[index] = e;
        }

        // 查找数组中是否有元素e
        bool contains(T e) {
            for (int i = 0; i < size; ++i) {
                if (data[i] == e) {
                    return true;
                }
            }
            return false;
        }

        // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
        int find(T e) {
            for (int i = 0; i < size; ++i) {
                if (data[i] == e) {
                    return i;
                }
            }
            return -1;
        }

        // 从数组中删除index位置的元素, 返回删除的元素
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

        // 从数组中删除第一个元素, 返回删除的元素
        T removeFirst() {
            return remove(0);
        }

        // 从数组中删除最后一个元素, 返回删除的元素
        T removeLast() {
            return remove(size - 1);
        }

        // 从数组中删除元素e
        void removeElement(T e) {
            int index = find(e);
            if (index != -1) {
                remove(index);
            }
        }

        //打印数组的所有元素
        void print() {
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                std::cout << data[i];
                if (i != size - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "]";
        }
    

    private:
        T *data;
        int size;
        int capacity;

        // 将数组空间的容量变成newCapacity大小
        void resize(int newCapacity) {
            T *newData = new T[newCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            data = newData;
            capacity = newCapacity;
            newData = nullptr;
            delete []newData;
        }
    };

    template<typename T>
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
            std::cout << "ArrayQueue: size = " << array->getSize() << ", capacity = " << array->getCapacity() << std::endl;
            std::cout << "front ";
            array->print();
            std::cout << " tail" << std::endl;
        }

    private:
        Array<T> *array;
    };
};
