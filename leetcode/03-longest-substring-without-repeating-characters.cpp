/*

Problem Statement:

Longest Substring Without Repeating Characters:

Given a string s, find the length of the longest substring without repeating characters.

*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool dp[256]; //For hashing
        for(int index = 0; index < 256; index++)
            dp[index] = false;
        int ans = 0,j=0;
        
        //Sliding Window Technique
        for(int i=0;i<s.length();i++)
        {
            while(j < s.length())
            {
                if(dp[s[j]])
                    break;
                dp[s[j]] = true;
                ans = max(ans,j-i+1);
                j++;
            }
            dp[s[i]]=false;
        }
        return ans;
    }
};

/*

Input:
s = "abab"

Output:
ans = 2

*/
