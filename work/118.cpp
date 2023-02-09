//
// Created by liufeiyu01 on 2023/2/9.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);

        if (1 == numRows) {
            result[0].push_back(1);
        }

        if (2 == numRows) {
            result[0].push_back(1);
            result[1].push_back(1);
            result[1].push_back(1);
        }

        if (numRows <= 2) {
            return result;
        }

        result[0].push_back(1);
        result[1].push_back(1);
        result[1].push_back(1);

        for (int i = 2; i < numRows; ++i) {
            for (int j = 0; j < i; j++) {
                if (0 == j) {
                    result[i].push_back(1);
                    continue;
                }

                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            }
            result[i].push_back(1);
        }

        return result;
    }
};

int main(void)
{
    Solution *tmp = new Solution;
    vector<vector<int>> result = tmp->generate(5);

    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}