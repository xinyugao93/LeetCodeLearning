#pragma once

/**
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>

namespace q238 {

class Solution238 {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> vecLeftMul(size, 1), vectRightMul(size, 1);
        std::vector<int> ans(size, 1);
        for(int i = 1; i < size; ++i) {
            vecLeftMul[i] = vecLeftMul[i - 1] * nums[i - 1];
            vectRightMul[size - 1 - i] = vectRightMul[size - i] * nums[size - i]; 
        }

        for(int i = 0; i < size; ++i) {
            ans[i] = vecLeftMul[i] * vectRightMul[i];
        }
        return ans;
    }
};

} // q238
