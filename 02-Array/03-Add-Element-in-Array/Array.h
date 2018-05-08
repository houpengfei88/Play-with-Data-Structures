//
// Created by hpf on 18-5-8.
//

class Array {
private:
    int *data;
    int size;
    int capacity;

public:
    class Full {
    };

    class Range {
    };
    Array(int capacity) {
        data = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    Array() {
        data = new int[10];
        size = 0;
        capacity = 10;
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

    void add(int index, int e) {
        if (size == capacity) {
            throw Full();
        }
        if (index < 0 || index > size) {
            throw Range();
        }
        for (int i = size - 1; i >= index; --i) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }

    void addFirst(int e) {
        add(0, e);
    }

    void addLast(int e) {
        add(size, e);
    }
};

