//
// Created by sky on 2023/3/22.
//

#include <queue>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (nullptr == head) {
            return head;
        }

        int total_len = 0;
        std::queue<ListNode*> que;
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;

        while (cur) {
            ++total_len;
            que.push(cur);
            cur = cur->next;
        }

        int target_pos = (total_len - 1) / 2;

        //0 1 3 4 7 1 2 6
        for (int i = 0; i < target_pos; ++i) {
            que.pop();
        }

        ListNode* pre = que.front();
        pre->next = pre->next->next;

        ListNode* result = dummy->next;

        delete dummy;

        return result;
    }
};