/*
Problem Statement:

String to Integer (atoi):

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1.  Read in and ignore any leading whitespace.
2.  Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
    This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3.  Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
4.  Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. 
    Change the sign as necessary (from step 2).
5.  If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. 
    Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
6.  Return the integer as the final result.

*/


class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int index = 0;
        while(index < s.length() && s[index] == ' ')
        {
            index++;
        }
        if(index <s.length() && s[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if(index <s.length() && s[index] == '+')
        {
            index++;
            sign = 1;
        }
        int ans = 0;
        while(index < s.length() && s[index] >= '0' && s[index] <= '9')
        {
            if(sign == -1 && (ans < INT_MIN/10 || (ans == INT_MIN/10 && (s[index] - '0') > 8)))
                return INT_MIN;
            if(sign == 1 && (ans > INT_MAX/10 || (ans == INT_MAX/10 && (s[index] - '0') > 7)))
                return INT_MAX;
            ans = ans*10 + sign*(s[index]-'0');
            index++;
        }
        return ans;
    }
};


/*

Input:
s = "-2131 and nothing"

Output:
ans = -2131


Input:
s = "nothing and 12912"

Output:
ans = 0


Input:
s = "           +12912"

Output:
ans = 12912

*/
