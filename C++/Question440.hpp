#pragma once

#include <vector>
#include <cstdint>
#include <queue>
#include <stack>

/**
 * 找到 [1, n] 中字典序第 k 小的数字
 * 
 * @param n 数字范围上限
 * @param k 第k小
 * @return 字典序第k小的数字
 */

namespace q440 {

class Solution440 {
public:
    int findKthNumber(int n, int k) {
        long long cur = 1; // 从1开始
        --k; // 因为我们从1开始，所以k要减1

        while(k > 0) {
            auto steps = _CountSteps(cur, n);
            if(steps <= k) {
                // 如果以curr为前缀的数字个数小于等于k
                // 说明答案不在以curr为前缀的子树中
                // 移动到下一个兄弟节点
                ++cur;
                k -= steps;
            } else {
                // 如果以curr为前缀的数字个数大于k
                // 说明答案在以curr为前缀的子树中
                // 深入到子树中
                cur *= 10;
                --k;
            }
        }

        return cur;
    }

private:
    /**
     * 计算以curr为前缀的数字在[1, n]范围内有多少个
     */
    long long _CountSteps(long long cur, long long n) {
        long long steps = 0, first = cur, last = cur;
        while(first <= n) {
            // 计算当前层级的数字个数
            steps += std::min(last, n) - first + 1;
            // 移动到下一层级
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }
};

} // namespace q440
