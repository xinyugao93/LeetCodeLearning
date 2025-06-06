#include "Question1061.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> s1{1, 2, 5, 4, 6, 10};
    auto it = std::max_element(s1.begin(), s1.end());
    std::cout << *it << std::endl;  
}