/*
Problem Statement:

4Sum:

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<pair<pair<int,int>,int>> check;
        sort(nums.begin(),nums.end());
        int i,j,m,n,sum;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                m = j+1;
                n = nums.size() - 1;
                while(m < n)
                {
                    sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if(sum == target)
                    {
                        if(check.find({{nums[i],nums[j]},nums[m]}) == check.end())
                        {
                            ans.push_back({nums[i],nums[j],nums[m],nums[n]});
                            check.insert({{nums[i],nums[j]},nums[m]});
                        }
                        m++;
                        n--;
                    }
                    else if(sum < target)
                        m++;
                    else
                        n--;
                }
            }
        }
        return ans;
        
    }
};


/*

Input:
nums = [1,0,-1,0,-2,2]
target = 0

Output:
ans = [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/
