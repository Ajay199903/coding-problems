/*
Problem Statement:

3Sum Closest:

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e6;
        int i,j,k,current;
        sort(nums.begin(),nums.end());
        for(i = 0; i < nums.size(); i++)
        {
            j = i+1;
            k = nums.size()-1;
            while(j < k)
            {
                current = nums[i] + nums[j] + nums[k];
                ans = (abs(ans-target) < abs(current-target)) ? ans : current;   
                if(target > current)
                    j++;
                else if(target < current)
                    k--;
                else
                    return target;
            }
        }
        return ans;
    }
};


/*

Input:
nums = [-1,2,1,-4]
target = 1

Output:
ans = 2

*/
