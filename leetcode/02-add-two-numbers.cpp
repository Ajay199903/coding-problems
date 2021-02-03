/*

Problem Statement:

Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a 
single digit. Add the two numbers and return the sum as a linked list.You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        int carry = 0;
        ListNode *ptr;
        ptr = ans;
        ptr->val = l1->val + l2->val;
        carry = ptr->val / 10;
        ptr->val = ptr->val % 10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != nullptr && l2 != nullptr)
        {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = l1->val + l2->val + carry;
            carry = ptr->val / 10;
            ptr->val = ptr->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = l1->val + carry;
            carry = ptr->val / 10;
            ptr->val = ptr->val % 10;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            ptr->next = new ListNode();
            ptr = ptr->next;
            ptr->val = l2->val + carry;
            carry = ptr->val / 10;
            ptr->val = ptr->val % 10;
            l2 = l2->next;
        }
        if(carry != 0)
        {
            
            ptr->next = new ListNode(carry);
        }
        return ans;
    }
};


/*

Input:
l1 = [1, 9, 9]
l2 = [2, 1, 3, 4]

Output:
ans = [3, 0, 3, 5]

*/
