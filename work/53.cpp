//
// Created by liufeiyu01 on 2023/2/8.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> fn(size, 0);
        fn[0] = nums[0];

        int result = nums[0];

        for (int i = 1; i < size; ++i) {
            fn[i] = max(fn[i - 1] + nums[i], nums[i]);
            result = max(fn[i], result);
        }

        return result;
    }
};

int main(void)
{
    Solution *tmp = new Solution;
    vector<int> nums = {5,4,-1,7,8};

    cout << tmp->maxSubArray(nums) << endl;
}