//
// Created by sky on 2023/3/16.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) return l2;
        if (nullptr == l2) return l1;

        ListNode* head = l1->val <= l2->val ? l1 : l2;
        ListNode* cur = head;
        ListNode* first = l1;
        ListNode* second = l2;

        if (head == first) {
            first = first->next;
        }
        else {
            second = second->next;
        }

        while (first && second) {
            if (first->val < second->val) {
                cur->next = first;
                cur = first;
                first = first->next;
            }
            else {
                cur->next = second;
                cur = second;
                second = second->next;
            }
        }

        if (first) {
            cur->next = first;
        }

        if (second) {
            cur->next = second;
        }

        return head;
    }
};
