#include <iostream>
#include <string>
#include "Solution.h"

int main() {
    std::vector<std::string> words = {"gin", "zen", "gig", "msg"};
    int size = Solution().uniqueMorseRepresentations(words);
    std::cout << "size = " << size << std::endl;
    return 0;
}
