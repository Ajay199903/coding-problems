/*
Problem Statement:

Longest Common Prefix:

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
        string ans = "";
        if(strs.size() == 0)
            return ans;
        char ch;
        for(int i = 0; i < strs[0].length(); i++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j].length() == i || strs[j][i] != strs[0][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};


/*

Input:
strs = ["that","this","the","them"]

Output:
ans = "th"

*/
