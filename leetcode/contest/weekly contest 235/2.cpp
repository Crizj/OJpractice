#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<set>
using namespace std;
class Solution 
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        vector<int> result(k,0);
        vector<pair<int,set<int>>> s;
        for(int i = 0; i < logs.size(); i++)
        {
            //s[logs[i][0]].insert(logs[i][1]);
            int id = logs[i][0];
            int j = 0;
            for(; j < s.size(); j++)
            {
                if(s[j].first == id)
                {
                    s[j].second.insert(logs[i][1]);
                    break;
                }
            }
            if(j == s.size())
            {
                pair<int,set<int>> temp;
                temp.first = id;
                temp.second.insert(logs[i][1]);
                s.push_back(temp);
            }
        }
        for(int i = 0; i < logs.size(); i++)
        {
            //if(s[i].size()-1 < k) result[s[i].size()-1]++;
            if(s[i].second.size() <= k) result[s[i].second.size()-1]++;
        }
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        return result;
    }
};
int main()
{
    vector<vector<int>> logs = {{1,1},{2,2},{2,3}};
    Solution temp;
    temp.findingUsersActiveMinutes(logs,4);
    return 0;
}