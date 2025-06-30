#pragma once

#include <string>
#include <cstdint>
#include <queue>

/**给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
 * 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组 
*/
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
