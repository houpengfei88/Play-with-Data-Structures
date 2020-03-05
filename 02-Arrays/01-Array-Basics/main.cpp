//
// Created by hpf on 18-5-8.
//

#include <iostream>

int main() {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    for (int j = 0; j < 10; ++j) {
        std::cout << arr[j] << " ";
    }
    std::cout << std::endl;

    int scores[] = {100, 99, 66};
    for (int k = 0; k < sizeof(scores) / sizeof(scores[0]); ++k) {
        std::cout << scores[k] << " ";
    }
    std::cout << std::endl;

    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    scores[0] = 98;
    for (int l = 0; l < sizeof(scores) / sizeof(scores[0]); ++l) {
        std::cout << scores[l] << " ";
    }
    std::cout << std::endl;
    return 0;
}

