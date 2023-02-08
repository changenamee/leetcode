//
// Created by sky on 2023/2/8.
//

#include "common.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        map<int, int> mp2;
        vector<int> result;

        for (auto num : nums1) {
            mp1[num]++;
        }

        for (auto num : nums2) {
            mp2[num]++;
        }

        for (auto num : nums1) {
            if (mp1[num] > 0 && mp2[num] > 0) {
                int cnt = min(mp1[num], mp2[num]);
                mp1.erase(num);
                mp2.erase(num);

                for (int i = 0; i < cnt; ++i) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }

    vector<int> intersectSorted(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> result;

        for (int i = 0, j = 0; i < len1 && j < len2;) {
            int val1 = nums1[i];
            int val2 = nums2[j];
            if (val1 == val2) {
                result.push_back(val1);
                i++;
                j++;
            }
            else if (val1 < val2) {
                i++;
            }
            else {
                j++;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution *tmp = new Solution;
    vector<int> vec1 = {4, 5, 9};
    vector<int> vec2 = {4, 4, 8, 8, 9};

    vector<int> result = tmp->intersect(vec1, vec2);
    for (auto num : result) {
        cout << num << " ";
    }

    cout << endl;

    result = tmp->intersectSorted(vec1, vec2);
    for (auto num : result) {
        cout << num << " ";
    }

    return  0;
}