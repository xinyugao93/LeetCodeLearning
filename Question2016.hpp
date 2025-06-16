#pragma once

/**
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。。
 */

#include <vector>
#include <algorithm>
#include <iostream>

namespace q2016 {

class Solution2016 {
public:
    int maximumDifference(std::vector<int>& nums) {
        auto size = nums.size();
        int ans = -1, preMin = nums[0];
        for(size_t i = 1; i < size; ++i) {
            if(nums[i] > preMin) {
                ans = std::max(ans, nums[i] - preMin);
            } else {
                preMin = nums[i];
            }
        }
        return ans;
    }
};

} // q2016
