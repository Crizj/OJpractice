/*
https://leetcode.com/problems/unique-paths/
so easy...

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
    vector<vector<int>> result;
    int m,n;
public:
    int uniquePaths(int m, int n) 
    {
        result.resize(m,vector<int>(n,-1));
        this->m = m;
        this->n = n;
        int r = dp(0,0);
        cout << r << endl;
        return r;
    }
    int dp(int i,int j)
    {
        if(result[i][j] != -1) return result[i][j];
        if(i+1 == m && j+1 == n)
        {
            result[i][j] = 1;
            return 1;
        }
        else if(i+1 == m) result[i][j] = dp(i,j+1);
        else if(j+1 == n) result[i][j] = dp(i+1,j);
        else result[i][j] = dp(i+1,j) + dp(i,j+1);
        return result[i][j];
    }
};
int main()
{
    while(1)
    {
        int m,n;
        cin >> m >> n;
        Solution s;
        s.uniquePaths(m,n);
    }
    return 0;
}