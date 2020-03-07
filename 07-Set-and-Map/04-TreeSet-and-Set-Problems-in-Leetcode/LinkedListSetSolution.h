//
// Created by hpf on 18-5-10.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string> &words) {
        std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                          ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                                          ".--", "-..-", "-.--", "--.."};
        LinkedListSet <std::string> linkedListSet;
        for (const std::string &word : words) {
            std::cout << '"' << word << '"' << " -> ";
            std::string code = "";
            for (char c : word) {
                code += morse[c - 'a'];
            }
            std::cout << '"' << code << '"' << std::endl;
            if (!linkedListSet.contains(code)) {
                linkedListSet.add(code);
            }
        }
        return linkedListSet.getSize();
    }

private:
    template<typename T>
    class LinkNode {
    public:
        T e;
        LinkNode<T> *next;

        LinkNode(T e, LinkNode<T> *next) : e(e), next(next) {}

        LinkNode(T e) : e(e), next(nullptr) {}
        
        LinkNode() : next(nullptr) {}
    };

    template<typename T>
    class LinkedList {
    public:
        LinkedList() {
            head = new LinkNode<T>();
            size = 0;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void add(int index, T e) {
            assert(index >= 0 && index <= size);
            LinkNode<T> *prev = head;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }
            prev->next = new LinkNode<T>(e, prev->next);
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
            LinkNode<T> *cur = head->next;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            return cur->e;
        }

        T getFirst() {
            return get(0);
        }

        T getLast() {
            return get(size - 1);
        }

        void set(int index, T e) {
            assert(index >= 0 && index < size);
            LinkNode<T> *cur = head->next;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            cur->e = e;
        }

        void setFirst(T e) {
            set(0, e);
        }

        void setLast(T e) {
            set(size - 1, e);
        }

        T remove(int index) {
            assert(index >= 0 && index < size);
            LinkNode<T> *prev = head;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }
            LinkNode<T> *retNode = prev->next;
            prev->next = retNode->next;
            retNode->next = nullptr;
            size--;
            return retNode->e;
        }

        T removeFirst() {
            return remove(0);
        }

        T removeLast() {
            return remove(size - 1);
        }

        void removeElement(T e) {
            LinkNode<T> *prev = head;
            while (prev->next != nullptr) {
                if (prev->next->e == e) {
                    break;
                }
                prev = prev->next;
            }

            if (prev->next != nullptr) {
                LinkNode<T> *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
                size--;
            }
        }

        bool contains(T e) {
            LinkNode<T> *cur = head;
            for (int i = 0; i < size; ++i) {
                cur = cur->next;
                if (cur->e == e) {
                    return true;
                }
            }
            return false;
        }

        void print() {
            LinkNode<T> *prev = head;
            std::cout << "LinkedList: size = " << size << std::endl;
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                prev = prev->next;
                std::cout << prev->e;
                if (i < size - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        }

    private:
        LinkNode<T> *head;
        int size;
    };

    template<typename T>
    class Set {
        virtual void add(T e) = 0;

        virtual void remove(T e) = 0;

        virtual bool contains(T e) = 0;

        virtual int getSize() = 0;
        
        virtual bool isEmpty() = 0;
    };

    template<typename T>
    class LinkedListSet : public Set<T>{
    public:
        LinkedListSet(){
            list = new LinkedList<T>();
        }

        int getSize(){
            return list->getSize();
        }

        bool isEmpty(){
            return list->isEmpty();
        }

        bool contains(T e){
            return list->contains(e);
        }

        void add(T e){
            if(!list->contains(e)){
                list->addFirst(e);
            }
        }

        void remove(T e){
            list->removeElement(e);
        }

    private:
        LinkedList<T> *list;
    };
};

