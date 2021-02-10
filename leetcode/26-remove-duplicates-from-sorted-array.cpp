/*
Problem Statement:

Remove Duplicates from Sorted Array:

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int len = 0;
        
        for(int i = 0 ; i < n; i++)
        {
            if(nums[len] != nums[i])
            {
                len++;
                nums[len] = nums[i];
            }
        }
        
        return len + 1;
    }
};





/*

Input:
nums = [0,0,1,1,1,2,2,3,3,4]

Output:
len = 5
nums = [0,1,2,3,4]

*/
