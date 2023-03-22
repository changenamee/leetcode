//
// Created by sky on 2023/3/22.
//

#include <unordered_map>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (nullptr == head) {
            return nullptr;
        }
        int total_len = 0;
        int target_pos = -1;
        int cur_pos = 0;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ++total_len;
            cur = cur->next;
        }

        target_pos = total_len - n + 1;
        pre = head;
        cur = head->next;
        cur_pos = 1;

        if (target_pos == cur_pos) {
            return head->next;
        }
        cur_pos = 2;
        // 1 2 3 4 5
        while (pre) {
            if (cur_pos++ == target_pos) {
                pre->next = cur->next;
                break;
            }
            pre = cur;
            if (cur->next) {
                cur = cur->next;
            }
        }

        return head;
    }

    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        if (nullptr == head) {
            return nullptr;
        }
        std::unordered_map<int, ListNode*> list_pos;

        int total_len = 0;
        int target_pos = -1;
        ListNode* cur = head;

//        1 2   1
        while (cur) {
            ++total_len;
            list_pos[total_len] = cur;
            cur = cur->next;
        }

        target_pos = total_len - n + 1;
        if (target_pos == 1) {
            return head->next;
        }

        ListNode* to_delete_node = list_pos[target_pos - 1];
        to_delete_node->next = to_delete_node->next->next;

        return head;
    }

    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        if (nullptr == head) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;

        std::stack<ListNode*> stk;

        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }

        for (int i = 0; i < n; ++i) {
            stk.pop();
        }

        ListNode* pre = stk.top();
        pre->next = pre->next->next;
        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }

    ListNode* removeNthFromEnd3(ListNode* head, int n) {
//         1 2 3 4 5
        if (nullptr == head) {
            return head;
        }

        int cnt = 0;

        ListNode* first = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* second = dummy;

        while (first) {
            first = first->next;
            ++cnt;

            if (cnt >= n + 1) {
                second = second->next;
            }
        }

        second->next = second->next->next;
        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};












