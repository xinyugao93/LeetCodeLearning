#pragma once

/**
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 */

#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_map>

namespace q594 {

class Solution594 {
public:
    int findLHS(std::vector<int>& nums) {
        return SlideWindowImpl_(nums);
    }

private:
    int SlideWindowImpl_(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int maxLen = 0;
        for(int right = 0; right < nums.size(); ++right) {
            if(nums[right] - nums[left] == 1) {
                maxLen = std::max(maxLen, right - left + 1);
            } else {
                while(left <= right && nums[right] - nums[left] > 1) {
                    ++left;
                }
            }
        }
        return maxLen;
    }

    int HashMapImpl_(std::vector<int>& nums) {
        std::unordered_map<int, int> mapNum2Cnt;
        for(auto num : nums) {
            ++mapNum2Cnt[num];
        }
        
        int maxLen = 0;
        for(auto& [key, value] : mapNum2Cnt) {
            if(mapNum2Cnt.count(key + 1) > 0) {
                maxLen = std::max(maxLen, mapNum2Cnt[key] + mapNum2Cnt[key + 1]);
            }
        }
        return maxLen;
    }
};

} // q594
