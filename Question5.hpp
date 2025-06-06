#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        auto size = s.size();
        std::vector<std::vector<bool>> dp(size, std::vector<bool>(size, false));
        for(int i = 0; i < size; ++i) {
            dp[i][i] = true;
        }

        int maxLen = 1;
        int begin = 0;
        for(int len = 2; len <= size; ++len) {
            for(int left = 0; left < size; ++left) {
                int right = left + len - 1;
                if(right >= size) {
                    break;
                }

                if(s[left] != s[right]) {
                    dp[left][right] = false;
                } else if(len < 3) {
                    dp[left][right] = true;
                } else {
                    dp[left][right] = dp[left + 1][right - 1];
                }

                if(dp[left][right] && len > maxLen) {
                    maxLen = len;
                    begin = left;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};