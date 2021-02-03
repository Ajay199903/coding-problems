/*
Problem Statement:

Remove Nth Node from end of List:

Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    int ct = 0;
    ListNode* getNode(ListNode* ptr,int n)
    {
        if(ptr == nullptr)
        {
            ct++;
            return ptr;
        }
        ListNode* tmp;
        tmp = getNode(ptr->next,n);
        if(ct == n)
        {
            ct++;
            return tmp;
        }
        else
        {
            ptr->next = tmp;
            ct++;
            return ptr;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = getNode(head,n);
        return head;
    }
};


/*

Input:
head = [2,3,1,5,6,7]
n = 3

Output:
ans = [2,3,1,6,7]

*/
