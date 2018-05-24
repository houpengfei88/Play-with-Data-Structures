//
// Created by hpf on 18-5-22.
//

#ifndef HEAP_SOLUTION_H
#define HEAP_SOLUTION_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <queue>


using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {
        assert(k > 0);

        unordered_map<int, int> freq;
        for (int num: nums)
            freq[num]++;

        assert(k <= freq.size());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
            if (pq.size() == k) {
                if (iter->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            } else
                pq.push(make_pair(iter->second, iter->first));
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

#endif //HEAP_SOLUTION_H
