/*
Problem Statement:

Letter Combinations of a Phone Number:

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 2 => a,b,c
 3 => d,e,f
 4 => g,h,i
 5 => j,k,l
 6 => m,n,o
 7 => p,q,r,s
 8 => t,u,v
 9 => w,x,y,z

*/



class Solution {
    vector<vector<char>> dp {{'a','b','c'},
                                 {'d','e','f'},
                                 {'g','h','i'},
                                 {'j','k','l'},
                                 {'m','n','o'},
                                 {'p','q','r','s'},
                                 {'t','u','v'},
                                 {'w','x','y','z'}};
    vector<string> ans;
public:
    void generateCombination(string& digits, int ind,string cur)
    {
        if(ind == digits.size())
        {
            ans.push_back(cur);
        }
        else
        {
            int itr = digits[ind] - '2';
            for(int i = 0; i < dp[itr].size(); i++)
                generateCombination(digits,ind+1,cur + dp[itr][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        generateCombination(digits,0,"");
        return ans;
    }
};


/*

Input:
digits = "23" 

Output:
ans = ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/
