/*
Problem Statement:

Reverse Nodes in k-Group:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

    Could you solve the problem in O(1) extra memory space?
    You may not alter the values in the list's nodes, only nodes itself may be changed.


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
    void getLength(ListNode* head,int &size)
    {
        while(head != nullptr)
        {
            size++;
            head = head->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        getLength(head,size);
        ListNode *bogus = new ListNode();
        bogus->next = head;
        head = bogus;
        int inv_cnt = size / k;
        ListNode *prev,*cur,*next;
        for(int i = 0; i < inv_cnt; i++)
        {
            prev = nullptr;
            cur = head->next;
            for(int j = 0; j < k; j++)
            {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head->next->next = cur;
            cur = head->next;
            head->next = prev;
            head = cur;
        }
        return bogus->next;
    }
};




/*

Input:
head = [1,2,3,4,5,6,7,8]
k = 3

Output:
ans = [3,2,1,6,5,4,7,8]

*/
