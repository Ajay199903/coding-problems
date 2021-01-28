/*
Problem Statement:

Roman To Integer:

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

*/

class Solution {
public:
    int romanToInt(string s) {
        int dp[256];
        dp['I'] = 1;
        dp['V'] = 5;
        dp['X'] = 10;
        dp['L'] = 50;
        dp['C'] = 100;
        dp['D'] = 500;
        dp['M'] = 1000;
        int ans = 0;
        for(int i = 0; i < s.length()-1; i++)
        {
            if(dp[s[i+1]] > dp[s[i]])
                ans = ans - dp[s[i]];
            else
                ans = ans + dp[s[i]];
        }
        ans = ans + dp[s[s.length()-1]];
        return ans;
    }
};


/*

Input: 
s = "MCMXCIV"

Output:
ans = 1994

*/