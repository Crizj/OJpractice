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
        vector<vector<int>> result(word1.size(),vector<int>(word2.size(),0));
        
        for(int i = 0; i < word1.size();i++)
        {
            for(int j = 0; j < word2.size(); j++)
            {
                if(word1[i] == word2[j])
                {
                    if(i-1 >= 0 && j-1 >= 0)
                    {
                        result[i][j] = result[i-1][j-1];
                    }
                    else
                    {
                        result[i][j] = max(i,j);
                    }
                }
                else
                { 
                    if(i == 0 && j == 0) result[i][j] = 1;
                    else if(i == 0) result[i][j] = result[i][j-1] + 1;
                    else if(j == 0) result[i][j] = result[i-1][j] + 1;
                    else 
                    {
                        result[i][j] = min(result[i-1][j-1]+1,result[i-1][j]+1);
                        result[i][j] = min(result[i][j],result[i][j-1]+1);
                    }
                }
            }
        }
        if(word1.empty())
        {
            cout << word2.size() << endl;
            return word2.size();
        }
        else if(word2.empty())
        {
            cout << word1.size() << endl;
            return word1.size();
        }
        cout << result[word1.size()-1][word2.size()-1] << endl;
        return result[word1.size()-1][word2.size()-1];
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