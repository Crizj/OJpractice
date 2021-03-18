#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
    vector<vector<int>> result;
    string input,pattern;
public:
    bool isMatch(string s, string p) 
    {
        for(int i = 0; i < s.length(); i++)
        {
            vector<int> row;
            for(int j = 0; j < p.length(); j++)
            {
                row.push_back(-1);
            }
            result.push_back(row);
        }
        input = s;
        pattern = p;
        if(dp(s.length()-1,p.length()-1) == 1) return true;
        return false;
    }
    int dp(int s,int p)
    {
        //结束递归的情况
        if(s == -1 && p == -1) return 1;
        else if(s == -1 && p >= 0 && pattern[p] == '*')
        {
            return dp(s,p-2);
        }
        else if(s == -1 || p == -1) return 0;

        //已经计算的情况
        if(result[s][p] != -1) return result[s][p];
        
        //继续递归的情况
        switch (pattern[p])
        {
        case '*':
        {
            int i = s;
            int res = 0;
            while(i >= 0)
            {
                int temp = dp(i,p-2);
                if(temp) res = 1;
                if(input[i] == pattern[p-1] || pattern[p-1] == '.')
                {
                    i--;
                }
                else break;
            }
            int temp = dp(i,p-2);
            if(temp) res = 1;
            result[s][p] = res;
            return result[s][p];
        }
        case '.':
        {
            result[s][p] = dp(s-1,p-1);
            return result[s][p];
        }
        default:
        {
            if(input[s] == pattern[p])
            {
                result[s][p] = dp(s-1,p-1);
                return result[s][p];
            }
            else
            {
                result[s][p] = 0;
                return 0;
            }
        }
        }
    }
};

int main()
{
    while(1)
    {
        Solution s;
        string input,pattern;
        cin >> input >> pattern;
        if(s.isMatch(input,pattern))
        {
            cout << "true" << endl;
        }
        else cout << "false" << endl;
    }
    return 0;
}