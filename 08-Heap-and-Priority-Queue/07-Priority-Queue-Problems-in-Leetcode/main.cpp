#include <iostream>
#include "Solution.h"


int main() {
    vector<int> nums = {1,1,1,2,2,3,6,6};
    int k = 2;
    vector<int> res = Solution::topKFrequent(nums,k);
    for(int num : res){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
