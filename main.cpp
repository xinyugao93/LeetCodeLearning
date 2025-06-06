#include "Question1061.hpp"
#include "Question5.hpp"
#include "Question3403.hpp"

#include <iostream>

int main() {
    q1061::Solution1061 sol1;
    std::cout << sol1.smallestEquivalentString("parker", "morris", "parser") << '\n';

    q5::Solution5 sol2;
    std::cout << sol2.longestPalindrome("babad") << '\n';

    q3403::Solution3403 sol3;
    std::cout << sol3.answerString("leetcode", 3) << '\n';
    return 0;
}
