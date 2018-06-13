#include <iostream>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"

template<typename T>
double testUF(T *uf, int m) {
    int size = uf->getSize();
    srand(10);
    clock_t startTime = clock();
    for (int i = 0; i < m; ++i) {
        int a = rand() % size;
        int b = rand() % size;
        uf->unionElements(a, b);
        uf->isConnected(a, b);
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    int size = 10000;
    int m = 10000;

    UnionFind1 *uf1 = new UnionFind1(size);
    std::cout << "UnionFind1 : " << testUF(uf1, m) << " s " << std::endl;
    UnionFind2 *uf2 = new UnionFind2(size);
    std::cout << "UnionFind2 : " << testUF(uf2, m) << " s " << std::endl;
    UnionFind3 *uf3 = new UnionFind3(size);
    std::cout << "UnionFind3 : " << testUF(uf3, m) << " s " << std::endl;
    UnionFind4 *uf4 = new UnionFind4(size);
    std::cout << "UnionFind4 : " << testUF(uf4, m) << " s " << std::endl;
	UnionFind5 *uf5 = new UnionFind5(size);
    std::cout << "UnionFind5 : " << testUF(uf5, m) << " s " << std::endl;

    delete[] uf1;
    delete[] uf2;
    delete[] uf3;
    delete[] uf4;
    delete[] uf5;
    return 0;
}
