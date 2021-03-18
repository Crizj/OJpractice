#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int num;
    cin >> num;
    vector<int> nums;
    for(int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int max = 0, sum = 0;
    int start = nums[0], end = nums[num-1],tempstart = nums[0];
    int presum = -1;
    for(int i = 0; i < num; i++)
    {
        sum += nums[i];
        if(sum < 0)
        {
            presum = sum;
            sum = 0;
            continue;
        }
        if(nums[i] > 0 && presum <= 0)
        {
            tempstart = nums[i];
        }
        if(sum > max)
        {
            max = sum;
            start = tempstart;
            end = nums[i];
        }
        presum = sum;
    }
    if(sum > 0) cout << max << " " << start << " " << end;
    else
    {
        for(int i = 0; i < num; i++)
        {
            if(nums[i] == 0)
            {
                cout << 0 << " " << nums[i] << " " << nums[i];
                return 0;
            }
        }
        cout << max << " " << start << " " << end;
    }
    return 0;
}