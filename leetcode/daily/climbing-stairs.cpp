/*
https://leetcode.com/problems/climbing-stairs/
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution 
{
public:
    int climbStairs(int n) 
    {
        vector<int> result;
        if(n >= 2)
        {
            result.resize(n+1,0);
        }
        else
        {
            result.resize(3,0);
        }
        result[0] = 0;
        result[1] = 1;
        result[2] = 2;
        for(int i = 3; i < result.size(); i++)
        {
            result[i] = result[i-1] + result[i-2];
        }
        cout << result[n] << endl;
        return result[n];
    }
};
int main()
{
    while(1)
    {
        int n;
        cin >> n;
        Solution s;
        s.climbStairs(n);
    }
    return 0;
}