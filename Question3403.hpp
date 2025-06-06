#pragma once

#include <string>
#include <cstdint>

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
