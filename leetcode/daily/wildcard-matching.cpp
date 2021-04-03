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
#include<time.h>
using namespace std;
//尝试1： Time Limit Exceeded
//input: abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab *aabb***aa**a******aa*

//最终还是AC了。原来是我的状态方程有问题
// P[i][j] = P[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?'), if p[j - 1] != '*';
// P[i][j] = P[i][j - 1] || P[i - 1][j], if p[j - 1] == '*'.
class Solution 
{
    vector<vector<int>> result;
    string s,pattern;
public:
    bool isMatch(string s, string p) 
    {
        this->s = s;
        int last = -1;
        for(int i = 0; i < p.length(); i++)
        {
            if(last >= 0 && p[i] == '*' && p[last] == '*')
            {
                //do nothing
            }
            else 
            {
                pattern.push_back(p[i]);
                last = i;
            }
        }
        //cout << pattern << endl;
        result.resize(s.length()+1,vector<int> (pattern.length()+1,-1));
        result[0][0] = 1;
        
        if(dp(s.length(),pattern.length()) == 1) 
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
        //cout << i << " " << j << endl;
        if(result[i][j] != -1) return result[i][j];
        if(i != 0 && j == 0) 
        {
            result[i][j] = 0;
            return 0;
        }
        if(pattern[j-1] == '*') //dp[i,j-1] || dp[i-1,j]
        {
            if(i > 0) 
            {
                result[i][j] = dp(i,j-1) || dp(i-1,j);
            }
            else result[i][j] = dp(i,j-1);
            return result[i][j];
        }
        else if(i == 0) 
        {
            result[i][j] = 0;
            return 0;
        }
        else if(s[i-1] == pattern[j-1] || pattern[j-1] == '?') 
        {
            result[i][j] = dp(i-1,j-1);
            return result[i][j];
        }
        result[i][j] = 0;
        return 0; // s[i] != p[j]
    }
};

int main()
{
    while(1)
    {
        clock_t start,end;
        string s,p;
        cin >> s >> p;
        Solution x;
        start = clock();
        x.isMatch(s,p);
        end = clock();
        cout << "Time:" << (double)(end-start)/1000 << endl;
    }
    return 0;
}