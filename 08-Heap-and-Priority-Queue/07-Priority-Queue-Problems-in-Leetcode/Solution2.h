//
// Created by hpf on 18-5-22.
//

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            record[nums[i]] += 1;
        }
        PriorityQueue<Freq> *priorityQueue = new PriorityQueue<Freq>();
        for (unordered_map<int, int>::iterator iterator1 = record.begin(); iterator1 != record.end(); ++iterator1) {
            if (priorityQueue->getSize() < k) {
                priorityQueue->enqueue(Freq(iterator1->first, iterator1->second));
            } else if (iterator1->second > priorityQueue->getFront().freq) {
                priorityQueue->dequeue();
                priorityQueue->enqueue(Freq(iterator1->first, iterator1->second));
            }
        }
        vector<int> res;
        while (!priorityQueue->isEmpty()) {
            res.push_back(priorityQueue->dequeue().e);
        }
        return res;
    }

private:
    class Freq {
    public:
        int e, freq;

        Freq(int e = 0, int freq = 0) {
            this->e = e;
            this->freq = freq;
        }

        bool operator<(const Freq &another) {
            if (this->freq < another.freq) {
                return false;
            } else {
                return true;
            }
        }

        bool operator>(const Freq &another) {
            if (this->freq > another.freq) {
                return false;
            } else {
                return true;
            }
        }
    };
    
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

		void resize(int newCapacity){
		    T *newData = new T[newCapacity];
		    for (int i = 0; i < size; ++i) {
		        newData[i] = data[i];
		    }
		    data = newData;
		    capacity = newCapacity;
		}

	public:
		class Full {
		};

		class Range {
		};

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

		Array(T arr[], int n) {
		    data = new T[n];
		    size = n;
		    for (int i = 0; i < n; ++i) {
		        data[i] = arr[i];
		    }
		    capacity = n;
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
		    if (index < 0 || index > size) {
		        throw Range();
		    }
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
		    if (index < 0 || index >= size) {
		        throw Range();
		    }
		    return data[index];
		}

		void set(int index, T e) {
		    if (index < 0 || index >= size) {
		        throw Range();
		    }
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
		    if (index < 0 || index >= size) {
		        throw Range();
		    }
		    T ret = data[index];
		    for (int i = index + 1; i < size; ++i) {
		        data[i - 1] = data[i];
		    }
		    size--;
		    if (size == capacity / 4 && capacity / 2 != 0){
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
		}

		void swap(int i, int j) {
		    if (i < 0 || i >= size || j < 0 || j >= size) {
		        throw Range();
		    }
		    T t = data[i];
		    data[i] = data[j];
		    data[j] = t;
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
	class MaxHeap {
	private:
		Array<T> *data;

		// 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
		int leftChild(int index) {
		    return index * 2 + 1;
		}

		// 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
		int rightChild(int index) {
		    return index * 2 + 2;
		}

		void shiftUp(int k) {
		    while (k > 0 && data->get(parent(k)) < data->get(k)) {
		        data->swap(k, parent(k));
		        k = parent(k);
		    }
		}
		
		void shiftDown(int k) {
		    while (leftChild(k) < data->getSize()) {
		        int j = leftChild(k);
		        if (j + 1 < data->getSize() && data->get(j + 1) > data->get(j)) {
		            j = rightChild(k);
		        }
		        if (data->get(k) > data->get(j)) {
		            break;
		        }
		        data->swap(k, j);
		        k = j;
		    }
		}
		
	public:
		class NoParent {
		};

		class Empty {
		};

		MaxHeap(int capacity) {
		    data = new Array<T>(capacity);
		}

		MaxHeap() {
		    data = new Array<T>();
		}

		MaxHeap(T arr[], int n){
		    data = new Array<T>(arr, n);
		    for (int i = parent(n - 1); i >= 0; --i) {
		        shiftDown(i);
		    }
		}

		int size() {
		    return data->getSize();
		}

		bool isEmpty() {
		    return data->isEmpty();
		}

		// 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
		int parent(int index) {
		    if (index == 0) {
		        throw NoParent();
		    }

		    return (index - 1) / 2;
		}

		void add(T e) {
		    data->addLast(e);
		    shiftUp(data->getSize() - 1);
		}
		
		T findeMax() {
		    if (data->isEmpty()) {
		        throw Empty();
		    }
		    return data->get(0);
		}

		T extractMax() {
		    T ret = findeMax();
		    data->swap(0, data->getSize() - 1);
		    data->removeLast();
		    shiftDown(0);
		    return ret;
		}
		
		T replace(T e){
		    T ret = findeMax();
		    data->set(0, e);
		    shiftDown(0);
		    return ret;
		}
		
		void print() {
			data->toPrint();
		}
	};
	
	template<class T>
	class PriorityQueue : public Queue<T> {
	private:
		MaxHeap<T> *maxHeap;
	public:
		PriorityQueue() {
		    maxHeap = new MaxHeap<T>();
		}

		int getSize() {
		    return maxHeap->size();
		}

		bool isEmpty() {
		    return maxHeap->isEmpty();
		}

		T getFront() {
		    return maxHeap->findeMax();
		}

		void enqueue(T e) {
		    maxHeap->add(e);
		}

		T dequeue() {
		    return maxHeap->extractMax();
		}

		void print() {
			std::cout << "Queue: size = " << maxHeap->size() << std::endl;
		    std::cout << "front ";
		    maxHeap->print();
		    std::cout << " tail" << std::endl;
		}
	};	
};
