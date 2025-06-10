#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>

/**
 * 给你一个由小写英文字母组成的字符串 s 。
 * 请你找出字符串中两个字符 a1 和 a2 的出现频次之间的 最大 差值 diff = a1 - a2，这两个字符需要满足：
 * a1 在字符串中出现 奇数次 ,
 * a2 在字符串中出现 偶数次 。
 * 返回 最大 差值。
 */

namespace q3442 {

class Solution3442 {
public:
    int maxDifference(std::string s) {
        std::unordered_map<char, int> mapChar2Cnt;
        for(auto ch : s) {
            ++mapChar2Cnt[ch];
        }

        int maxOdd = 0, minEven = INT32_MAX;
        for(auto &pr : mapChar2Cnt) {
            if(pr.second % 2 == 0) {
                minEven = std::min(minEven, pr.second);
            } else {
                maxOdd = std::max(maxOdd, pr.second);
            }
        }

        return maxOdd - minEven;
    }
};

} // namespace q3442
