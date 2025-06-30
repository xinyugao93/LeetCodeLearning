#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

/**
给你一个长度为 n 的整数数组 nums，以及一个正整数 k 。

将这个数组划分为 n / 3 个长度为 3 的子数组，并满足以下条件：

子数组中 任意 两个元素的差必须 小于或等于 k 。
返回一个 二维数组 ，包含所有的子数组。如果不可能满足条件，就返回一个空数组。如果有多个答案，返回 任意一个 即可。
 */
namespace q2966 {

class Solution2966 {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i += 3) {
            if(nums[i + 2] - nums[i] > k) {
                return {};
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};

} // namespace q2966
