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
        ArrayQueue<std::pair<TreeNode *, int>> *queue = new ArrayQueue<std::pair<TreeNode *, int>>();
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
	class Array {
	public:
		class Empty {
		};

		class Range {
		};

		/**
		 * 构造函数,传入数组容量构造Array
		 * @param capacity 数组容量
		 */
		Array(int capacity) {
		    this->data = new T[capacity];
		    this->size = 0;
		    this->capacity = capacity;
		}

		/**
		 * 析构函数
		 */
		~Array() {
		    delete[] data;
		    data = nullptr;
		}

		/**
		 * 得到数组的大小
		 * @return 数组大小
		 */
		int getSize() {
		    return size;
		}

		/**
		 * 判断数组是否为空
		 * @return 数组为空返回 true
		 */
		bool isEmpty() {
		    return size == 0;
		}

		/**
		 * 得到数组的容量
		 * @return 数组的容量
		 */
		int getCapacity() {
		    return capacity;
		}

		/**
		 * 向数组某一位置添加元素
		 * @param index 数组中的位置序号
		 * @param e 插入的元素
		 * @return 添加成功返回 true
		 */
		bool add(int index, T e) {
		    if (index < 0 || index > size) {
		        std::cout << "Add failed. Require index >= 0 and index <= size" << std::endl;
		        return false;
		    }
		    if (size == capacity) {
		        resize(2 * capacity);
		    }
		    for (int i = size - 1; i >= index; --i) {
		        data[i + 1] = data[i];
		    }
		    data[index] = e;
		    size++;
		    return true;
		}

		/**
		 * 向数组头部添加元素
		 * @param e 要添加的元素
		 * @return 添加成功返回 true
		 */
		bool addFirst(T e) {
		    return add(0, e);
		}

		/**
		 * 向数组尾部添加元素
		 * @param e 要添加的元素
		 * @return 添加成功返回 true
		 */
		bool addLast(T e) {
		    return add(size, e);
		}

		/**
		 * 删除数组中某一位置的元素
		 * @param index 数组中的序号
		 * @return 被删除的值
		 */
		T remove(int index) {
		    if (index < 0 || index > size) {
		        std::cout << "Remove failed. Require index >= 0 and index < size" << std::endl;
		        throw Range();
		    }
		    if (size == 0) {
		        throw Empty();
		    }
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

		bool removeElement(T e) {
		    int index = find(e);
		    if (index >= 0) {
		        remove(index);
		        return true;
		    }
		    return false;
		}

		T get(int index) {
		    if (index < 0 || index >= size) {
		        std::cout << "Get failed. " << std::endl;
		        throw Range();
		    }
		    return data[index];
		}

		T getFirst() {
		    return get(0);
		}

		T getLast() {
		    return get(size - 1);
		}

		bool set(int index, T e) {
		    if (index < 0 || index >= size) {
		        return false;
		    }
		    data[index] = e;
		    return true;
		}

		bool setFirst(T e) {
		    return set(0, e);
		}

		bool setLast(T e) {
		    return set(size - 1, e);
		}

		bool contains(T e) {
		    for (int i = 0; i < size; ++i) {
		        if (data[i] == e) {
		            return true;
		        }
		    }
		    return false;
		}

		/**
		 * 寻找元素e在数组中的位置
		 * @param e 想要查找的元素
		 * @return 元素的位置
		 */
		int find(T e) {
		    for (int i = 0; i < size; ++i) {
		        if (data[i] == e) {
		            return i;
		        }
		    }
		    return -1;
		}

		/**
		 * 打印数组的所有元素
		 */
		void print() {
		    std::cout << "Array: size = " << size << ", capacity = " << capacity << std::endl;
		    toPrint();
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

	private:
		/**
		 * data 静态数组
		 * size 数组大小
		 * capacity 数组容量
		 */
		T *data;
		int size;
		int capacity;

		/**
		 * 重新设置数组容量
		 * @param newCapacity 新的数组容量
		 * @return 新的数组
		 */
		void resize(int newCapacity) {
		    T *newData = new T[newCapacity];
		    for (int i = 0; i < size; ++i) {
		        newData[i] = data[i];
		    }
		    data = newData;
		    capacity = newCapacity;
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
