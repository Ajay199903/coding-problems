/*
Problem Statement:

3Sum:

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i = 0, j, k;
        while(i < nums.size())
        {
            if(nums[i] > 0)
                break;
            j = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] < -nums[i])
                    j++;
                else if(nums[j] + nums[k] > -nums[i])
                    k--;
                else
                {
                    vector<int> tmp{nums[i],nums[j],nums[k]};
                    if(!(ans.size() > 0 && tmp[0] == ans[ans.size()-1][0] && tmp[1] == ans[ans.size()-1][1]))
                        ans.push_back(tmp);
                    j++;
                    k--;
                }
            }
            i++;
            while(i < nums.size() && nums[i] == nums[i-1])
            {
                i++;
            }
        }
        return ans;
    }
};



/*

Input:
nums = [-1,0,1,2,-1,-4]

Output:
ans = [[-1,-1,2],[-1,0,1]]

*/
