/*
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution 
{
    vector<vector<int>> result;
    int m,n;
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        this->m = grid.size();
        this->n = grid[0].size();
        result.resize(m,vector<int>(n,-1));
        int r = dp(0,0,grid);
        cout << r << endl;
        return r;
    }
    int dp(int i,int j,vector<vector<int>>& grid)
    {
        if(result[i][j] != -1) return result[i][j];
        result[i][j] = 0;
        result[i][j] += grid[i][j];
        if(i+1 == m && j+1 == n)
        {
            return result[i][j];
        }
        else if(i+1 == m) result[i][j] += dp(i,j+1,grid);
        else if(j+1 == n) result[i][j] += dp(i+1,j,grid);
        else result[i][j] += min(dp(i+1,j,grid),dp(i,j+1,grid));
        return result[i][j];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input = {{1,2,3},{4,5,6}};
    s.minPathSum(input);
    return 0;
}
