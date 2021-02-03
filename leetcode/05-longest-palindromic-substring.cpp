/*
Problem Statement:

Longest Palindromic Substring:

Given a string s, return the longest palindromic substring in s.

*/

class Solution {
public:
    int lengthOfPalindrome(string &s,int l,int h)
    {
        int len = 0;
        if(l == h)
        {
            len += 1;
            l--;
            h++;
        }
        while(l >= 0 && h <= s.length())
        {
            if(s[l] != s[h])
                break;
            len += 2;
            l--;
            h++;
        }
        return len;
    }
    string longestPalindrome(string s) {
        int len = 0,tmp,mid = 0;
        for(int i = 0; i < s.length(); i++)
        {
            tmp = max(lengthOfPalindrome(s,i,i+1),lengthOfPalindrome(s,i,i));
            if(len < tmp)
            {   
                len = tmp;
                mid = i;
            }
        }
        if (len == 0)
            return "";
        int start = mid - (len - 1) / 2;
        return s.substr(start,len);
    }
};


/*

Input:
s = "acbcdefcbca"

Output:
ans = "cbc"

*/
