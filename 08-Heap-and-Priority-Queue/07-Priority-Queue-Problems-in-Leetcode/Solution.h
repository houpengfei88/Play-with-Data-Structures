//
// Created by hpf on 18-5-22.
//

#ifndef HEAP_SOLUTION_H
#define HEAP_SOLUTION_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "PriorityQueue.h"

using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            record[nums[i]] += 1;
        }
        for (unordered_map<int,int>::iterator iterator2 = record.begin();iterator2!= record.end();++iterator2) {
            std::cout << iterator2->first << " " << iterator2->second << std::endl;
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
};

#endif //HEAP_SOLUTION_H
