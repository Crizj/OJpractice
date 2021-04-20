#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class RecentCounter 
{
    vector<int> result;
public:
    RecentCounter() 
    {
        
    }
    
    int ping(int t) 
    {
        result.push_back(t);
        //start: t-3000 end: t
        int i = 0;
        for(; i < result.size(); i++)
        {
            if(result[i] + 3000 > t) break;
        }
        return result.size() - i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */