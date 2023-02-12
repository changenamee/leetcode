//
// Created by sky on 2023/2/12.
//
#include "common.h"

class Solution {
public:
    int firstUniqChar(string s) {
        map<int, int> charCnt;

        for (auto ch : s) {
            charCnt[ch]++;
        }

        int i = 0;
        for (auto ch : s) {
            if (charCnt[ch] == 1) {
                return i;
            }
            i++;
        }

        return -1;
    }
};