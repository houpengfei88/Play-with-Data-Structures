#include <iostream>
#include "Trie.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Trie *trie = new Trie();
    std::string test = "test";
    trie->add(test);
    trie->add("nihao");
    trie->add("hello");
    std::cout << std::boolalpha << trie->contains(test) << " " << trie->contains("able") << std::endl;
    std::cout << std::boolalpha << trie->contains("nihao") << " " << trie->contains("hao") << std::endl;
    std::cout << std::boolalpha << trie->contains("hello") << " " << trie->contains("hel") << std::endl;
    std::cout << "size : " << trie->getSize() << std::endl;
    return 0;
}
