/*
https://leetcode.com/problems/maximum-subarray/
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum. 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> result(nums.size(),0);  
        if(nums.size() > 0) result[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] >= 0)
            {
                if(result[i-1] > 0) result[i] = result[i-1] + nums[i];
                else result[i] = nums[i];
            }
            else
            {
                result[i] = max(result[i-1]+nums[i],nums[i]);
            }
        }
        int max = -999999;
        for(int i = 0; i < nums.size(); i++)
        {
            if(result[i] > max) max = result[i];
        }
        cout << max << endl;
        return max;
    }
};

int main()
{
    vector<int> num = {5,4,-1,7,8};
    Solution s;
    s.maxSubArray(num);
    return 0;
}