/*
Problem Statement:

Integer to Roman:

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

*/


class Solution {
public:
    void appendToString(string &s, char ch, int times)
    {
        int i = 0;
        while(i < times)
        {
            s += ch;
            i++;
        }
    }
    void selectRoman(int &num,char roman,char prefix,string &s,int current,int prefixInteger)
    {
        int times;
        times = num / current;
        appendToString(s,roman,times);
        num = num % current;
        if(num >= prefixInteger)
        {
            s += prefix;
            s +=roman;
            num -= prefixInteger;
        }
    }
    string intToRoman(int num) {
        string ans = "";
        selectRoman(num,'M','C',ans,1000,900);
        selectRoman(num,'D','C',ans,500,400);
        selectRoman(num,'C','X',ans,100,90);
        selectRoman(num,'L','X',ans,50,40);
        selectRoman(num,'X','I',ans,10,9);
        selectRoman(num,'V','I',ans,5,4);
        appendToString(ans,'I',num);
        return ans;
    }
};



/*

Input:
num = 3994 

Output:
ans = "MMMCMXCIV"

*/