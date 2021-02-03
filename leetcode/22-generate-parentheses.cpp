/*
Problem Statement:

Generate Parentheses:

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

*/


class Solution {
public:
    vector<string> ans;
    void createCombination(int open,int close,int n,string current)
    {
        if(close == n)
        {
            ans.push_back(current);
            return;
        }
        if(open < n)
            createCombination(open+1,close,n,current + "(");
        if(close < open)
            createCombination(open,close+1,n,current + ")");
        
    }
    vector<string> generateParenthesis(int n) {
        createCombination(0,0,n,"");
        return ans;
    }
};




/*

Input:
n = 3

Output:
ans = ["((()))","(()())","(())()","()(())","()()()"]

*/
