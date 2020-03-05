//
// Created by hpf on 18-5-8.
//

#include <iostream>
#include <cassert>

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
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i != size - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
	    std::cout << std::endl;
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

