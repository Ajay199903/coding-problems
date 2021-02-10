/*
Problem Statement:

Reverse Integer:

Given a signed 32-bit integer x, return x with its digits reversed. 

If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

*/

class Solution {
public:
    int reverse(int x) {
        int ans=0,rem;
        while(x>=10 || x <= -10)
        {
            rem = x % 10;
            x = x / 10;
            ans = ans  * 10 + rem;
        }
        rem = x % 10;
        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && rem > 7))
            return 0;
        else if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && rem < -8))
            return 0;
        else
            return ans * 10 + rem;
    }
};

/*

Input:
x = 123

Output:
ans = 321

Input:
x = -123

Output:
ans = -321

*/
