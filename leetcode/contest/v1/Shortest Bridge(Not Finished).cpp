#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//2021/4/20, 16:44: 我想回宿舍打游戏，想吃饭，不想做这题了。。。
//一个很好的思路链接： https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus

class Solution 
{
    vector<vector<int>> map;
    vector<vector<int>> A;
public:
    int shortestBridge(vector<vector<int>>& A) 
    {
        int label = 0;
        map.resize(A.size(),vector<int>(A[0].size(),-1));
        this->A = A;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[i].size(); j++)
            {
                if(A[i][j] == 1 && map[i][j] == 0 && label == 0)
                {
                    dfs(i,j,label);
                    label++;
                }
                else if(A[i][j] == 1 && map[i][j] != 0) 
                {
                    //???
                }
            }
        }

    }
    void dfs(int i, int j, int label)  
    {
        if( i < 0 || j < 0 || i >= A.size() || j >= A[i].size() || A[i][j] == 0) return ;
        map[i][j] = label;
        dfs(i+1,j,label);
        dfs(i-1,j,label);
        dfs(i,j+1,label);
        dfs(i,j-1,label);
    }
};