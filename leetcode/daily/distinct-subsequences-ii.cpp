/*
https://leetcode.com/problems/distinct-subsequences-ii/
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution 
{
public:
    int distinctSubseqII(string S) 
    {
        vector<long long int> dp(S.length()+1,0);
        vector<int> m(26,-1);
        dp[0] = 1;
        m[S[0]-'a'] = 0;
        long long int mod = 1e9+7;
        //cout << S[0]-'a' << endl;
        for(int i = 1; i < S.length(); i++)
        {
            if(m[S[i]-'a'] == -1)   //input char has never appeared before
            {
                dp[i] = (dp[i-1]*2+1)%mod;
                //dp[i] = dp[i]%1000000007;
            }
            else 
            {
                //dp[i] = dp[i-1]*2;
                if(m[S[i]-'a']-1 >= 0) 
                {

                    dp[i] = (dp[i-1]*2 - dp[m[S[i]-'a']-1] + mod )%mod;
                }
                else dp[i] = (dp[i-1]*2)%mod;
            }
            m[S[i]-'a'] = i;
        }
        cout << dp[S.length()-1] << endl;
        return dp[S.length()-1];
    }
};

int main()
{
    while(1)
    {
        string input;
        cin >> input;
        Solution s;
        s.distinctSubseqII(input);
    }
    return 0;
}