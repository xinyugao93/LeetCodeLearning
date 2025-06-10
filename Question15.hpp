#pragma once

#include <vector>
#include <cstdint>
#include <queue>
#include <stack>

/**
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
 * 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 *  */

#include <vector>
#include <algorithm>

namespace q15 {

class Solution15 {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        std::vector<std::vector<int>> ans;
        for(int first = 0; first < size; ++first) {
            if(first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            int target = nums[first];
            int third  = size - 1;
            for(int second = first + 1; second < size; ++second) {
                if(second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }

                while(second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                if(second == third) {
                    break;
                }

                if(target == nums[second] + nums[third]) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
    }
};

} // namespace q15
