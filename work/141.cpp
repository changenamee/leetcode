//
// Created by sky on 2023/2/12.
//

#include "common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head) {
            return false;
        }

        ListNode *first = head;
        ListNode *second = head->next;

        while (second && second->next) {
            if (first == second) {
                return true;
            }

            first = first->next;
            second = second->next->next;
        }

        return false;
    }
};