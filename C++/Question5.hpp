#pragma once

#include <string>
#include <vector>

/**
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 */
namespace q5 {

class Solution5 {
public:
    std::string longestPalindrome(const std::string& s) {
        if(s.empty()) return "";
        int start = 0;
        int end = 0;

        auto expand = [&](int left, int right){
            while(left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right]) {
                --left;
                ++right;
            }
            return std::pair<int,int>{left + 1, right - 1};
        };

        for(int i = 0; i < static_cast<int>(s.size()); ++i) {
            auto [l1, r1] = expand(i, i);
            if(r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }
            auto [l2, r2] = expand(i, i + 1);
            if(r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

} // namespace q5
