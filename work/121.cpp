//
// Created by liufeiyu01 on 2023/2/9.
//

#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            return 0;
        }

        int little = prices[0];
        int result = 0;
        int i = 0;
        for (auto price : prices) {
            result = max(result, price - little);
            little = min(little, price);
        }

        return result;
    }
};

int main(void)
{
    Solution *tmp = new Solution;
    vector<int> vec = {7,6,4,3,1};

    cout << tmp->maxProfit(vec);

    return 0;
}