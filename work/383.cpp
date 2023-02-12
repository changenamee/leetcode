//
// Created by sky on 2023/2/12.
//
#include "common.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazineContained;

        for (auto ch : magazine) {
            magazineContained[ch]++;
        }

        for (auto need : ransomNote) {
            if (magazineContained[need] > 0) {
                magazineContained[need]--;
                continue;
            }
            return false;
        }
        return true;
    }
};