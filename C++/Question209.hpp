#pragma once

/**
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>

namespace q209 {

class Solution209 {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int size = nums.size();
        int ans = size + 1;
        int sum = 0;
        int left = 0;
        for(int i = 0; i < size; ++i) {
            sum += nums[i];
            if(sum < target) {
                continue;
            }
            ans = std::min(ans, i - left + 1);
            while(sum >= target) {
                sum -= nums[left];
                ++left;
                if(sum >= target) {
                    ans = std::min(ans, i - left + 1);
                }
            }
        }
        return ans == size + 1 ? 0 : ans;
    }
};

} // q209
