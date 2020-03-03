/*
 * NumArray.h
 *
 *  Created on: 2018年6月5日
 *      Author: hpf
 */

class NumArray {
public:
    NumArray(vector<int> nums) {
        data.resize(nums.size());
        sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i ++) {
        	data[i] = nums[i];
        }
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i ++) {
        	sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    void update(int i, int val) {
    	data[i] = val;
        for (int k = i + 1; k < sum.size(); k ++) {
        	sum[k] = sum[k - 1] + data[k - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }

private:
	vector<int> data;
	vector<int> sum;
};
