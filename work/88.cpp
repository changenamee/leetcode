//
// Created by liufeiyu01 on 2023/2/8.
//

#include "common.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total_len = m + n - 1;
        int first = m - 1;
        int second = n - 1;
        int val = 0;

        while (first >=0 || second >=0) {
            if (first == -1) {
                val = nums2[second--];
            }
            else if (second == -1) {
                val = nums1[first--];
            }
            else if (nums1[first] > nums2[second]) {
                val = nums1[first--];
            }
            else {
                val = nums2[second--];
            }

            nums1[total_len--] = val;
        }
    }
};

int main(void)
{
    Solution *tmp = new Solution;

    vector<int> vec1 = {1, 0};
    vector<int> vec2 = {2};
    tmp->merge(vec1, 1, vec2, 1);

    for (auto num : vec1) {
        cout << num << " ";
    }

    return 0;
}
