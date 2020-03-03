//
// Created by hpf on 18-5-14.
//

class Solution {
public:
    static vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums1.size(); ++i) {
            record[nums1[i]] += 1;
        }
        vector<int> resultMap;
        for (int i = 0; i < nums2.size(); i++) {
            if (record[nums2[i]] > 0) {
                resultMap.push_back(nums2[i]);
                record[nums2[i]] --;
            }
        }
        return resultMap;
    }
};
