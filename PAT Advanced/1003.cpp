#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> map;
vector<int> value;

void dfs(int current,int dest,int val,int & num,vector<bool> visited,int teams,int & minpath, int & max)
{
    if(dest == current)
    {
        teams += value[current];
        if(val < minpath)
        {
            num = 1;
            max = teams;
            minpath = val;
            return;
        }
        else if(val == minpath)
        {
            num ++;
            if(max < teams) max = teams;
        }
        return;
    }
    if(visited[current] == true)
    {
        return;
    }
    for(int i = 0; i < map[current].size(); i++)
    {
        if(map[current][i] != 0)
        {
            visited[current] = true;
            dfs(i,dest,val+map[current][i],num,visited,teams + value[current],minpath,max);
        }
    }
}
int main()
{
   // vector<vector<int>> map;
    int num_of_city,num_of_road;
    cin >> num_of_city;
    for(int i = 0; i < num_of_city; i++)
    {
        vector<int> temp;
        for(int j = 0; j < num_of_city; j++)
        {
            temp.push_back(0);
        }
        map.push_back(temp);
    }
    int cur_pos,des_pos;
    cin >> num_of_road >> cur_pos >> des_pos;
    for(int i = 0; i < num_of_city; i++)
    {
        int value_i;
        cin >> value_i;
        value.push_back(value_i);
    }
    for(int i = 0; i < num_of_road; i++)
    {
        int start,end,val;
        cin >> start >> end >> val;
        map[start][end] = val;
        map[end][start] = val;
    }
    int max = 0,num = 0, minpath = 9999999;
    vector<bool> visited;
    for (int i = 0; i < num_of_city; i++)
    {
        visited.push_back(false);
    }
    
    dfs(cur_pos,des_pos,0,num,visited,0,minpath,max);
    cout << num << " " << max << " " << minpath;
    while (1)
    {
        /* wait */
    }
    
    return 0;
}