/*
 * NumArray.h
 *
 *  Created on: 2018年6月5日
 *      Author: hpf
 */

class NumArray {
public:
    NumArray(vector<int> nums) {
    	if(nums.size() > 0){
    		int *data = new int[nums.size()];
			for (int i = 0; i < nums.size(); ++i) {
				data[i] = nums[i];
			}
			segmentTree = new SegmentTree<int>(data, nums.size(), [](int a, int b) -> int {
		        return a + b;
		    });
    	}
    }

	void update(int i, int val) {
		assert(segmentTree != nullptr);
    	segmentTree->set(i, val);
    }

    int sumRange(int i, int j) {
    	assert(segmentTree != nullptr);
    	return segmentTree->query(i,j);
    }
private:
    
    template<class T>
    class SegmentTree {
    private:
        T *tree;
        T *data;
        int size;
    	std::function<T(T, T)> function;
    	
        int leftChild(int index) {
            return index * 2 + 1;
        }

        int rightChild(int index) {
            return index * 2 + 2;
        }
        
        void buildSegmentTree(int treeIndex, int l, int r) {
            if (l == r) {
                tree[treeIndex] = data[l];
                return;
            }
            int leftTreeIndex = leftChild(treeIndex);
            int rightTreeIndex = rightChild(treeIndex);
            int mid = l + (r - l) / 2;

            buildSegmentTree(leftTreeIndex, l, mid);
            buildSegmentTree(rightTreeIndex, mid + 1, r);
            tree[treeIndex] = function(tree[leftTreeIndex], tree[rightTreeIndex]);
        }
        
        T query(int treeIndex, int l, int r, int queryL, int queryR) {
            if (l == queryL && r == queryR) {
                return tree[treeIndex];
            }

            int mid = l + (r - l) / 2;
            int leftTreeIndex = leftChild(treeIndex);
            int rightTreeIndex = rightChild(treeIndex);

            if (queryL >= mid + 1) {
                return query(rightTreeIndex, mid + 1, r, queryL, queryR);
            } else if (queryR <= mid) {
                return query(leftTreeIndex, l, mid, queryL, queryR);
            }

            T leftResult = query(leftTreeIndex, l, mid, queryL, mid);
            T rightResult = query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
            return function(leftResult, rightResult);
        }
        
        void set(int treeIndex, int l, int r, int index, T e) {
        	if(l == r) {
        		tree[treeIndex] = e;
        		return;
        	}
        	
        	int mid = l + (r - l) / 2;
        	int leftTreeIndex = leftChild(treeIndex);
            int rightTreeIndex = rightChild(treeIndex);
            if(index >= mid + 1) {
            	set(rightTreeIndex, mid + 1, r, index, e);
            }else {
            	set(leftTreeIndex, l, mid, index, e);
            }
            
            tree[treeIndex] = function(tree[leftTreeIndex], tree[rightTreeIndex]);
        }

    public:
        SegmentTree(T arr[], int n, std::function<T(T, T)> function) {
            this->function = function;
            data = new T[n];
            for (int i = 0; i < n; ++i) {
                data[i] = arr[i];
            }
            tree = new T[n * 4];
            size = n;
            buildSegmentTree(0, 0, size - 1);
        }

        int getSize() {
            return size;
        }

        T get(int index) {
            assert(index >= 0 && index < size);
            return data[index];
        }
        
        T query(int queryL, int queryR) {
            assert(queryL >= 0 && queryL < size && queryR >= 0 && queryR < size && queryL <= queryR);
            return query(0, 0, size - 1, queryL, queryR);
        }

		void set(int index, T e) {
			assert(index >= 0 && index < size);
			data[index] = e;
			set(0, 0, size - 1, index, e);
		}
    	void print() {
            std::cout << "[";
            for (int i = 0; i < size * 4; ++i) {
                if (tree[i] != NULL) {
                    std::cout << tree[i];
                } else {
                    std::cout << "0";
                }
                if (i != size * 4 - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        }
    };
    SegmentTree<int> *segmentTree;
};
