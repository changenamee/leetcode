//
// Created by liufeiyu01 on 2023/2/14.
//

#include "common.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowNCol(9, vector<int>(9));
        vector<vector<int>> colNRow(9, vector<int>(9));
        vector<vector<int>> qu(9, vector<int>(9));
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char val = board[row][col];
                if (val == '.') {
                    continue;
                }
                if (++rowNCol[row][val-'1'] > 1) {
                    return false;
                }
                if (++colNRow[col][val - '1'] > 1) {
                    return false;
                }

                int tmpRow = (row / 3) + (row / 3) * 2 + col / 3;
                if (++qu[tmpRow][val - '1'] > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};