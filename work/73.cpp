//
// Created by liufeiyu01 on 2023/2/14.
//

#include "common.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int row0Flag = 0;
        int col0Flag = 0;

        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) {
                row0Flag = 1;
            }
        }

        for (int i = 0; i < col; ++i) {
            if (matrix[0][i] == 0) {
                col0Flag = 1;
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < col; ++i) {
            if (row0Flag == 1) {
                matrix[0][i] = 0;
            }
        }

        for (int i = 0; i < row; ++i) {
            if (col0Flag == 1) {
                matrix[i][0] = 0;
            }
        }
    }
};