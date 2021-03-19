/*
32. Longest Valid Parentheses
Hard
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution 
{
    vector<int> result;     //以i
public:
    int longestValidParentheses(string s) 
    {
        result.resize(s.length(),0);
        //test
        //cout << "size:" << result.size() << endl;
        for(int i = 0; i < result.size(); i++)
        {
            if(s[i] == '(' || i == 0) result[i] = 0;
            else if(s[i-1] == '(')
            {
                if(i == 1) result[i] = 2;
                else result[i] = result[i-2] + 2;
            }
            else if((i-1-result[i-1]) < 0) result[i] = 0;
            else if(s[i-1-result[i-1]] == ')') result[i] = 0;
            else
            {
                result[i] = result[i-1] + 2;
                if((i-2-result[i-1]) >= 0)
                {
                    result[i] += result[i-2-result[i-1]];
                }
            }
        }
        int max = 0;
        for(int i = 0; i < result.size(); i++)
        {
            if(result[i] > max) max = result[i];
        }
        cout << max << endl;
        return max;
    }
};

int main()
{
    while(1)
    {
        string input;
        cin >> input;
        Solution s;
        s.longestValidParentheses(input);
    }
    return 0;
}