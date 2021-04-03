/*
https://leetcode.com/problems/edit-distance/
编辑距离
ps.南大常考题
呜呜呜呜 还是不会做
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> result(word1.size()+1,vector<int>(word2.size()+1,0));

        for (int i = 1; i <= word1.size(); i++) 
        {
            result[i][0] = i;
        }
        for (int j = 1; j <= word2.size(); j++) 
        {
            result[0][j] = j;
        }
        for(int i = 1; i <= word1.size();i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                if(word1[i] == word2[j])
                {
                    result[i][j] = result[i-1][j-1];
                }
                else
                { 
                    result[i][j] = min(result[i-1][j-1]+1,result[i-1][j]+1);
                    result[i][j] = min(result[i][j],result[i][j-1]+1);
                }
            }
        }
        cout << result[word1.size()][word2.size()] << endl;
        return result[word1.size()][word2.size()];
    }
};

int main()
{
    while(1)
    {
        string a,b;
        cin >> a >> b;
        Solution s;
        s.minDistance(a,b);
    }
    // int x = 0|1,y = 2|1;
    // cout << x << " " << endl;
    // cout << y << endl;
    return 0;
}