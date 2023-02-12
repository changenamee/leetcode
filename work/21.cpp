//
// Created by sky on 2023/2/12.
//
#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (nullptr == list1) {
            return list2;
        }
        if (nullptr == list2) {
            return list1;
        }

        ListNode *result = NULL;
        if (list1->val < list2->val) {
            result = list1;
            list1 = list1->next;
        }
        else {
            result = list2;
            list2 = list2->next;
        }

        ListNode *cur = result;
        ListNode *first = list1;
        ListNode *second = list2;

        while (first && second) {
            if (first->val < second->val) {
                cur->next = first;
                first = first->next;
            }
            else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }

        if (first) {
            cur->next = first;
        }

        if (second) {
            cur->next = second;
        }

        return result;
    }
};