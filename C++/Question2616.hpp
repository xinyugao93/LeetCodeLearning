#pragma once

#include <vector>
#include <algorithm>

/**
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 p 。
 * 请你从 nums 中找到 p 个下标对，每个下标对对应数值取差值，你需要使得这 p 个差值的 最大值 最小。同时，你需要确保每个下标在这 p 个下标对中最多出现一次。
 * 对于一个下标对 i 和 j ，这一对的差值为 |nums[i] - nums[j]| ，其中 |x| 表示 x 的 绝对值 。
 * 请你返回 p 个下标对对应数值 最大差值 的 最小值 。
 */

namespace q2616 {

class Solution2616 {
public:
    int minimizeMax(std::vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());
        auto check = [&](int mx) {
            int cnt = 0;
            for(int i = 0; i < nums.size() - 1; ++i) {
                if(nums[i + 1] - nums[i] <= mx) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
        };

        int left = 0, right = nums.back() - nums[0];
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

} // q2616