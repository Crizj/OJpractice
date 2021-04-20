#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Solution 
{
    vector<int> dict;
    vector<int> result;
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        dict = nums;
        result.resize(target+1,-1);
        int output = dp(target);
        cout << output << endl;
        return output;
    }
    int dp(int target)
    {
        if(target < 0) return 0;
        else if(target == 0) return 1;
        if(result[target] != -1) return result[target];
        result[target] = 0;
        for(int i  = 0; i < dict.size(); i++)
        {
            result[target] += dp(target-dict[i]);
        } 
        return result[target];
    } 
};

int main()
{
    vector<int> input = {9};
    int target = 3;
    Solution s;
    s.combinationSum4(input,target);
    return 0;
}

