#pragma once

#include <vector>
#include <algorithm>

/**
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * 说明：你不能倾斜容器。
 */
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