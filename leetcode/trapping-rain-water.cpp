/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        /*
            The solution used by me is not the best.
            check https://leetcode.com/problems/trapping-rain-water/solution/ for better solution.
        */
        vector<int> result(height.size(),0);
        int max_id = -1,max = 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(i == 0 || i == 1) result[i] = 0;
            else if(height[i] <= height[i-1]) result[i] = result[i-1];
            else 
            {
                int h = (height[i] < max)?height[i]:max;
                int sum = 0;
                int j = i - 1;
                for(; j >= max_id + 1; j--)
                {
                    if(h <= height[j]) break;
                    sum = sum + h - height[j];
                }
                if(j > 0) sum += result[j];
                result[i] = sum;
            }

            if(height[i] >= max)
            {
                max = height[i];
                max_id = i;
            }
        }
        
        if((int)(height.size()-1) >= 0) 
        {
            cout << result[height.size()-1] << endl;
            return result[height.size()-1];
        }
        else 
        {
            cout << 0 << endl;
            return 0;
        }
    }
};
//0 1 0 2 1 0 1 3 2 1 2 1
int main()
{
    //vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    //vector<int> input = {4,2,0,3,2,5};
    vector<int> input = {5,4,1,2};
    //vector<int> input = {9,6,8,8,5,6,3};
    int temp;
    Solution s;
    s.trap(input);
    return 0;
}