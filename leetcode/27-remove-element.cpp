/*
Problem Statement:

Remove Element:

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != val)
                nums[i-cnt] = nums[i];
            else
                cnt++;
        }
        return n-cnt;
    }
};




/*

Input:
nums = [2,1,3,2,2,4,2,0]
val = 2

Output:
len = 4
nums = [1,3,4,0]

*/
