#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution 
{
    vector<vector<int>> next = 
    {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    long long int mod = 1e9+7;
public:
    int knightDialer(int n) 
    {
        long long int result = 0;
        vector<long long int> tempre(10,1);
        for(int i = 1; i < n; i++)
        {
            vector<long long int> temp(10,0);
            for(int i = 0; i < 10; i++)
            {
                if(next[i].size() == 3) temp[i] = tempre[next[i][0]]+tempre[next[i][1]]+tempre[next[i][2]];
                else if(next[i].size() == 2) temp[i] = tempre[next[i][0]]+tempre[next[i][1]];
                temp[i] = temp[i]%mod;
            }
            tempre = temp;
        }
        for(int i = 0; i < 10; i++)
        {
            result = (tempre[i]+result)%mod;
        }
        return result;
    }
};

int main()
{
    while(1)
    {
        int n;
        cin >> n;
        Solution s;
        cout << s.knightDialer(n) << endl;
    }
    return 0;
}