//
// Created by liufeiyu01 on 2023/2/8.
//

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> cur;
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (cur.end() != cur.find(target - nums[i])
                && cur[target - nums[i]] != i)
            {
                return {cur[target - nums[i]], i};
            }

            cur[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main()
{
    Solution *tmp = new Solution;
    vector<int> nums = {3, 2, 4};

    vector<int> result = tmp->twoSum(nums, 6);
    for (auto num : result) {
        cout << num << " ";
    }

    return 0;
}