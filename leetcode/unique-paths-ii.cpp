/*
https://leetcode.com/problems/unique-paths-ii/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
    vector<vector<int>> result;
    vector<vector<int>> obstacle;
    int m,n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        obstacle = obstacleGrid;
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        result.resize(m,vector<int>(n,-1));
        int r = dp(0,0);
        cout << r << endl;
        return r;
    }
    int dp(int i,int j)
    {
        if(result[i][j] != -1) return result[i][j];
        if(obstacle[i][j] == 1) return 0;
        if(i+1 == m && j+1 == n)
        {
            if(obstacle[i][j] == 1) 
            {
                result[i][j] = 0;
                return 0;
            }
            result[i][j] = 1;
            return 1;
        }
        else if(i+1 == m) 
        {
            if(obstacle[i][j+1] == 1) 
            {
                result[i][j] = 0;
                return 0;
            }
            result[i][j] = dp(i,j+1);
        }
        else if(j+1 == n) 
        {
            if(obstacle[i+1][j] == 1) 
            {
                result[i][j] = 0;
                return 0;
            }
            result[i][j] = dp(i+1,j);
        }
        else 
        {
            if(obstacle[i+1][j] == 1) result[i][j] = dp(i,j+1);
            else if(obstacle[i][j+1] == 1) result[i][j] = dp(i+1,j);
            else result[i][j] = dp(i+1,j) + dp(i,j+1);
        }
        return result[i][j];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> input = {{1,0}};
    s.uniquePathsWithObstacles(input);
    return 0;
}
