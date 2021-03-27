/*
https://leetcode.com/problems/distinct-subsequences/
hard
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        vector<vector<long long int>> dp(s.length()+1,vector<long long int>(t.length()+1,0));
        for(int i = 0; i <= s.length(); i++) dp[i][0] = 1;
        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = 1; j <= t.length(); j++)
            {
                if(i < j) ; //dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout << dp[s.length()][t.length()] << endl;
        return dp[s.length()][t.length()];
    }
};

int main()
{
    while(1)
    {
        string a,b;
        cin >> a >> b;
        Solution s;
        s.numDistinct(a,b);
    }
    return 0;
}