#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
/*
我好菜啊

我的代码：
*/
class Solution 
{
    vector<int> input;
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        int local = 0, global = 0;
        input = A;
        for(int i = 0; i + 1 < A.size(); i++)
        {
            if(A[i] > A[i+1]) local++;
        }
        global = merge(0,A.size()-1);
        cout << global << ":" << local << endl;
        for(int i = 0; i < input.size(); i++)
        {
            cout << input[i] << " ";
        }
        if(local == global) return true;
        return false;
    }
    int merge(int left, int right)
    {
        if(left >= right) return 0;
        int mid = (left+right)/2;
        int result = merge(left,mid) + merge(mid+1,right);
        int i = left, j = mid + 1,id = 0,size = right-left+1;
        vector<int> temp(size,0);
        while(id < size)
        {
            if(input[i] > input[j])
            {
                temp[id] = input[j];
                j++;
                result += (mid-i+1);
                id++;
                if(j > right) break;
            }
            else
            {
                temp[id] = input[i];
                i++;
                id++;
                if(i > mid) break;
            }
        }
        if(id < size && i > mid)
        {
            while(id < size)
            {
                temp[id] = input[j];
                id++;
                j++;
            }
        }
        if(id < size && j > right)
        {
            while(id < size)
            {
                temp[id] = input[i];
                id++;
                i++;
            }
        }
        for(int k = 0; k < size; k++)
        {
            input[left + k] = temp[k];
        }
        return result;
    }
};

//大佬的代码：

class Solution 
{
public:
    bool isIdealPermutation(vector<int>& A) 
    {
        for(int i = 0; i < A.size(); i++)
        {
            if(abs(A[i]-i) >= 2) return false;
        }
        return true;
    }
};

int main()
{
    vector<int> input = {5,4,1,0,3,2};
    Solution s;
    s.isIdealPermutation(input);
}

