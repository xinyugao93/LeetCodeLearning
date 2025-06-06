#pragma once

#include <string>
#include <cstdint>

using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(1 == numFriends) {
            return word;
        }

        auto size = word.size();
        uint32_t left = 0;
        string ret = "";
        for(auto right = size - numFriends; right < size; ++right, ++left) {
            string tmp = word.substr(left, size - numFriends + 1);
            if(ret < tmp) {
                ret = tmp;
            }
        }
        for(; left < size; ++left) {
            string tmp = word.substr(left, size - left);
            if(ret < tmp) {
                ret = tmp;
            }
        }

        return ret;
    }
};