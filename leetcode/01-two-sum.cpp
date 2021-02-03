/*
Problem Statement:

Two Sums:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

Assume that each input would have exactly one solution, and same element cannot be used twice.

Return the answer in any order.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp; // For mapping array elements with their index
        set<int> s;
        vector<int> ans;
        for(int index = 0; index < nums.size(); index++)
        {
            if(s.find(target - nums[index]) != s.end())
            {
                ans.push_back(mp[target-nums[index]]);
                ans.push_back(index);
                break;
            }
            mp.insert({nums[index],index});
            s.insert(nums[index]);
        }
        return ans;
    }
};

/*

Input:
nums = [2,7,11,15], target = 9

Output:
ans = [0,1]

*/
