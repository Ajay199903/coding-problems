/*
Problem Statement:

Merge Two Sorted Lists:

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(), *ptr = nullptr;
        ptr = ans;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                ptr->next = l1;
                ptr = ptr-> next;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr)
        {
            ptr->next = l1;
        }
        if(l2 != nullptr)
        {
            ptr->next = l2;
        }
        ptr = ans;
        ans = ans->next;
        delete ptr;
        return ans;
    }
};



/*

Input:
l1 = [1,2,5,7]
l2 = [2,4]

Ouptut: 
ans = [1,2,2,4,5,7]

*/
