/*
link:https://leetcode.com/problems/wildcard-matching/

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution 
{
    vector<vector<int>> result;
    string s,p;
public:
    bool isMatch(string s, string p) 
    {
        result.resize(s.length()+1,vector<int> (p.length()+1,-1));
        result[0][0] = 1;
        this->s = s;
        this->p = p;
        if(dp(s.length(),p.length()) == 1) 
        {
            cout << "true" << endl;
            return true;
        }
        else
        {
            cout << "false" << endl;
            return false;
        }
    }
    int dp(int i, int j)
    {
        if(result[i][j] != -1) return result[i][j];
        if(i != 0 && j == 0) return 0;
        if(p[j-1] == '*') //dp[i,j-1] || dp[i-1,j-1] || dp[i-2,j-1] || ... ||  dp[1][j-1] || dp[0,j-1]
        {
            for(int m = 0; m <= i; m++)
            {
                if(dp(m,j-1) == 1) return 1;
            }
        }
        else if(s[i-1] == p[j-1] || p[j-1] == '?') return dp(i-1,j-1);
        return 0; // s[i] != p[j]
    }
};

int main()
{
    while(1)
    {
        string s,p;
        cin >> s >> p;
        Solution x;
        x.isMatch(s,p);
    }
    return 0;
}