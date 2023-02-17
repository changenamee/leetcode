//
// Created by liufeiyu01 on 2023/2/17.
//
#include "common.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<int, int> result;

        for (auto c : s) {
            result[c]++;
        }

        for (auto c : t) {
            if (result.find(c) == result.end() || result[c] == 0) {
                return false;
            }
            result[c]--;
        }

        return true;
    }
};