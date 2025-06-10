#pragma once

#include <string>
#include <cstdint>
#include <queue>

namespace q3170 {

class Solution3170 {
public:
    std::string clearStars(std::string s) {
        using P = std::pair<char, int>;
        auto cmp = [](const P& lhs, const P& rhs) {
            if(lhs.first != rhs.first) {
                return lhs.first > rhs.first;
            }
            return lhs.second < rhs.second;
        };

        std::priority_queue<P, std::vector<P>, decltype(cmp)> pqCh(cmp);
        for(auto i = 0; i < s.size(); ++i) {
            if('*' != s[i]) {
                pqCh.emplace(s[i], i);
            } else {
                s[pqCh.top().second] = '*';
                pqCh.pop();
            }
        }
        std::string ans;
        for(auto ch : s) {
            if(ch != '*') {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

} // namespace q3170
