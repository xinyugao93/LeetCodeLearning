#pragma once

/**
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。
 */

#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>

namespace q322 {

class Solution322 {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            int minNum = INT32_MAX;
            for(auto coin : coins) {
                if(i < coin || -1 == dp[i - coin]) {
                    continue;
                }
                minNum = std::min(dp[i - coin] + 1, minNum);
            }
            if(INT32_MAX != minNum) {
                dp[i] = minNum;
            }
        }

        return dp[amount];
    }
};

} // q322
