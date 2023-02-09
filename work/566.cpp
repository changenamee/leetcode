//
// Created by liufeiyu01 on 2023/2/9.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if ((m * n) != (r * c)) {
            return mat;
        }

        vector<vector<int>> result(r);

        int first = 0;
        int second = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (second == c) {
                    second = 0;
                    first++;
                }

                result[first].push_back(mat[i][j]);
                second++;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution *tmp = new Solution;
    vector<vector<int>> vec = {{1, 2}, {3, 4}};

    vector<vector<int>> result = tmp->matrixReshape(vec, 2, 4);
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}