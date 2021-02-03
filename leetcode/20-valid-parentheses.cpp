/*
Problem Statement:

Valid Parentheses:

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.


*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
                case ')' : if(!stk.empty() && stk.top() == '(')
                                stk.pop();
                            else
                                return false;
                            break;
                case '}' : if(!stk.empty() && stk.top() == '{')
                                stk.pop();
                            else
                                return false;
                            break;
                case ']' : if(!stk.empty() && stk.top() == '[')
                                stk.pop();
                            else
                                return false;
                            break;
                default: stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};






/*

Input:
s = "({}[])"

Output:
ans = true

*/
