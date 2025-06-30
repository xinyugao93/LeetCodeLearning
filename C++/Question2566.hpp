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

namespace q2566 {

class Solution2566 {
public:
    int minMaxDifference(int num) {
        auto numStr = std::to_string(num);
        auto maxNumStr = numStr, minNumStr = numStr;
        auto changeMaxCh = ' ', changeMinCh = numStr[0];
        for(int i = 0; i < numStr.size(); ++i) {
            if(numStr[i] != '9' && ' ' == changeMaxCh) {
                changeMaxCh = numStr[i];
            }
            if(numStr[i] == changeMaxCh) {
                maxNumStr[i] = '9';
            }
            if(numStr[i] == changeMinCh) {
                minNumStr[i] = '0';
            }
        }

        std::cout << maxNumStr << " " << minNumStr << std::endl;
        try{
            int maxNum = std::stoi(maxNumStr);
            int minNum = std::stoi(minNumStr);
            std::cout << maxNum << " " << minNum << std::endl;
            return maxNum - minNum;
        } catch(std::exception &e) {
            std::cout << "string to int error: " << e.what() << '\n';
        } catch(...) {
            std::cout << "string to int unknown error: " << '\n';
        }

        return -1;
    }
};

}
