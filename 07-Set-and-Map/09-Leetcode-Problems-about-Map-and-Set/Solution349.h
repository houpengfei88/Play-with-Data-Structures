//
// Created by hpf on 18-5-14.
//

class Solution {
public:
    static vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        set<int> *set1 = new set<int>();
        for (int num : nums1) {
            set1->insert(num);
        }
        std::cout << std::endl;
        vector<int> list;
        for (int num1 : nums2) {
            for (set<int>::iterator iterator1= set1->begin();iterator1 != set1->end();iterator1++){
                if (*iterator1 == num1){
                    list.push_back(num1);
                    set1->erase(num1);
                }
            }
        }
        return list;
    }
};
