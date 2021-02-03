/*
Problem Statement:

Palindrome Number:

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.


*/


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        if(x % 10 == 0)
            return false;
        int rev = 0;
        while(x > rev)
        {
            rev = rev*10 + x % 10;
            x /= 10;
        }
        if(x == rev || x == rev/10)
            return true;
        else
            return false;
    }
};

/*

Input:
x = 121

Output:
true

Input:
x = -121

Output:
false

*/
