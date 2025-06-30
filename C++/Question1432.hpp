#pragma once

/**
 * 给你一个整数 num 。你知道 Danny Mittal 会偷偷将 0 到 9 中的一个数字 替换 成另一个数字。
 * 请你返回将 num 中 恰好一个 数字进行替换后，得到的最大值和最小值的差为多少。
 * 注意：
 * 当 Danny 将一个数字 d1 替换成另一个数字 d2 时，Danny 需要将 nums 中所有 d1 都替换成 d2 .
 * Danny 可以将一个数字替换成它自己，也就是说 num 可以不变。
 * Danny 可以将数字分别替换成两个不同的数字分别得到最大值和最小值。
 * 替换后得到的数字可以包含前导 0 。
 */

#include <string>
#include <iostream>

namespace q1432 {

class Solution1432 {
public:
    int maxDiff(int num) {
        auto numStr = std::to_string(num);
        auto maxPos = numStr.find_first_not_of('9');
        char changeMaxCh = '9';
        if(maxPos != std::string::npos) {
            changeMaxCh = numStr[maxPos];
        }

        bool firstPos = false;
        char changeMinCh = '0';
        if(numStr[0] != '1') {
            changeMinCh = numStr[0];
            firstPos = true;
        } else {
            std::size_t minPos = 0;
            do {
                minPos = numStr.find_first_not_of('0', minPos + 1);
                if(minPos != std::string::npos && numStr[minPos] != numStr[0]) {
                    changeMinCh = numStr[minPos];
                    break;
                } else if(minPos == std::string::npos) {
                    changeMinCh = numStr[0];
                    firstPos = true;
                    break;
                }
            } while(true);
        }

        std::string maxNumStr = numStr, minNumStr = numStr;
        for(int i = 0; i < numStr.size(); ++i) {
            if(numStr[i] == changeMaxCh) {
                maxNumStr[i] = '9';
            }
            if(numStr[i] == changeMinCh) {
                if(firstPos) {
                    minNumStr[i] = '1';
                } else {
                    minNumStr[i] = '0';
                }
            }
        }

        try {
            return std::stoi(maxNumStr) - std::stoi(minNumStr);
        } catch(std::exception &e) {
            
        }

        return -1;
    }
};

}
