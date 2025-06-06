#pragma once

#include <vector>
#include <algorithm>

namespace q11 {

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while(left < right) {
            int water = _CalculateWater(height[left], height[right], right - left);
            if(water > res) {
                res = water;
            }

            if(height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return res;
    }

private:
    inline int _CalculateWater(int leftH, int rightH, int len) {
        int height = std::min(leftH, rightH);
        return height * len;
    }
};

}