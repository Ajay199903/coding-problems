/*
Problem Statement:

ZigZag Conversion:

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 

P   A    H   N
 A P  L S I I G
  Y    I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows.

*/

class Solution {
public:
    string convert(string s, int numRows) {
        int direction = 1,row = 0;
        if(numRows == 1)
            return s;
        string pattern[numRows];
        for(int i = 0; i < s.length(); i++)
        {
            pattern[row].push_back(s[i]);
            if(row + direction == numRows || row + direction < 0)
                direction *= -1;
            row += direction;
        }
        string ans = "";
        for(int i = 0; i < numRows; i++)
            ans += pattern[i];
        return ans;
    }
};


/*

Input: 
s = "PAYPALISHIRING" 
numRows = 4 

Output:
"PINALSIGYAHRPI"

*/
