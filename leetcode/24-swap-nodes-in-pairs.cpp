/*
Problem Statement:


Swap Nodes in Pairs:

Given a linked list, swap every two adjacent nodes and return its head.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *bogus = new ListNode();
        bogus->next = head;
        ListNode *cur1 = bogus;
        ListNode *cur2 = bogus->next;
        while(cur2 != nullptr && cur2->next != nullptr)
        {
            cur1->next = cur2->next;
            cur1 = cur1->next;
            cur2->next = cur1->next;
            cur1->next = cur2;
            cur1 = cur2;
            cur2 = cur2->next;
        }
        return bogus->next;
    }
};





/*

Input:
head = [1,2,3,4,5,6]

Output:
ans = [2,1,4,3,6,5]

*/
