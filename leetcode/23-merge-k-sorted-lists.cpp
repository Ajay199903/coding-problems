/*
Problem Statement:

Merge k Sorted Lists:

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

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
    ListNode* merging(ListNode *left,ListNode *right)
    {
        ListNode *bogus = new ListNode();
        ListNode *cur = bogus;
        while(left != nullptr && right != nullptr)
        {
            if(left->val < right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left != nullptr)
            cur->next = left;
        else
            cur->next = right;
        return bogus->next;
    }
    ListNode* divideAndMerge(vector<ListNode*>& lists,int l,int h)
    {
        if(l == h)
            return lists[l];
        int mid = (l + h) / 2;
        ListNode *left = divideAndMerge(lists,l,mid);
        ListNode *right = divideAndMerge(lists,mid+1,h);
        return merging(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        return divideAndMerge(lists,0,lists.size()-1);
    }
};





/*

Input:
lists = [[1,4,5],[1,3,4],[2,6]]

Output:
ans = [1,1,2,3,4,4,5,6]

*/
