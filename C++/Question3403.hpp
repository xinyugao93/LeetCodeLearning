#pragma once

#include <string>
#include <cstdint>

/**
 * 给你一个字符串 word 和一个整数 numFriends。

Alice 正在为她的 numFriends 位朋友组织一个游戏。游戏分为多个回合，在每一回合中：

word 被分割成 numFriends 个 非空 字符串，且该分割方式与之前的任意回合所采用的都 不完全相同 。
所有分割出的字符串都会被放入一个盒子中。
在所有回合结束后，找出盒子中 字典序最大的 字符串。
 */
namespace q3403 {

class Solution3403 {
public:
    std::string answerString(const std::string& word, int numFriends) {
        if(numFriends <= 1) {
            return word;
        }

        const std::size_t keep = word.size() - numFriends + 1;
        std::size_t drop = word.size() - keep;
        std::string result;
        result.reserve(word.size());

        for(char c : word) {
            while(!result.empty() && result.back() < c && drop > 0) {
                result.pop_back();
                --drop;
            }
            result.push_back(c);
        }

        if(result.size() > keep) {
            result.resize(keep);
        }
        return result;
    }
};

} // namespace q3403
