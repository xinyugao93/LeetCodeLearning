#pragma once

#include <vector>
#include <cstdint>
#include <queue>
#include <stack>

/**
 * 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
 * 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
 */
namespace q386 {

class Solution386 {
public:
public:
    std::vector<int> lexicalOrder(int n) {
        for(int i = 1; i < 10; ++i) {
            _DFS(i, n);
        }

        return _res;
    }

private:
    void _DFS(int curNum, int n) {
        if(curNum > n) {
            return;
        }

        _res.push_back(curNum);
        for(int i = 0; i < 10; ++i) {
            int nextNum = curNum * 10 + i;
            if(nextNum > n) {
                break;
            }
            _DFS(nextNum, n);
        }
    }

    void _DFSIterative(int n) {
        std::stack<int> stkNum;
        for(int i = 9; i >= 0; --i) {
            if(i <= n) {
                stkNum.push(i);
            }
        }

        while(!stkNum.empty()) {
            int curNum = stkNum.top();
            stkNum.pop();

            _res.push_back(curNum);
            for(int i = 9; i >= 0; --i) {
                int nextNum = curNum * 10 + i;
                if(nextNum < n) {
                    stkNum.push(nextNum);
                }
            }
        }
    }
private:
    std::vector<int> _res;
};

} // namespace q386
