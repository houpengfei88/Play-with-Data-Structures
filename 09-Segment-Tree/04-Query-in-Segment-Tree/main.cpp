#include <iostream>
#include "SegmentTree.h"

int main() {
    int nums[] = {-2, 0, 3, -5, 2, -1};
    SegmentTree<int> *segmentTree = new SegmentTree<int>(nums, sizeof(nums) / sizeof(int), [](int a, int b) -> int {
        return a + b;
    });
    std::cout << segmentTree->query(2,5) << std::endl;
    segmentTree->print();
    return 0;
}
