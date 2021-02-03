/*
Problem Statement:

Regular Expression Matching:

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

*/


class Solution {
    int dp[21][31];
public:
    
    bool checkRegExp(string &s, int i, string &p, int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j] == 1;
        if(j == p.length())
        {
            if(i == s.length())
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
            return dp[i][j] == 1;
        }
        bool current,rest;
        current = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        if(j + 1 < p.length() && p[j+1] == '*')
            rest = (current && checkRegExp(s,i+1,p,j)) || checkRegExp(s,i,p,j+2);
        else
            rest = current && checkRegExp(s,i+1,p,j+1);
        if(rest)
            dp[i][j] = 1;
        else
            dp[i][j] = 0;
        return rest;
        
    }
    bool isMatch(string s, string p) {
        for(int i = 0; i <= s.length(); i++)
            for(int j = 0; j <= p.length(); j++)
                dp[i][j] = -1;
        return checkRegExp(s,0,p,0);
    }
};



/*

Input:
s = "aa"
p = "a*"

Output:
ans = true

*/
