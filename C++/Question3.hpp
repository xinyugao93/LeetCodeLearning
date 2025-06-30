#pragma once

#include <string>
#include <vector>
#include <unordered_set>

/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。。
 */
namespace q3 {

class Solution3 {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> setCh;
        int maxLen = 0;
        int rpoint = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(i != 0) {
                setCh.erase(s[i - 1]);
            } 
            while(rpoint + 1 < s.size() && 0 == setCh.count(s[rpoint + 1])) {
                setCh.insert(s[rpoint + 1]);
                ++rpoint;
            }
            maxLen = std::max(maxLen, rpoint - i + 1);
        }
        return maxLen;
    }
};

} // namespace q3
