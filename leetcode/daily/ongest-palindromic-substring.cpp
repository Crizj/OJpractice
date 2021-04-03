#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
    vector<vector<int>> result;
    //result[i][j] means s[i...j] is a palindromic substring 
public:
    string longestPalindrome(string s) 
    {
        for(int i = 0; i < s.length(); i++)
        {
            vector<int> temp;
            for(int j = 0; j < s.length(); j++)
            {
                if(j == i) 
                {
                    temp.push_back(1);
                }
                else 
                {
                    temp.push_back(0);
                }
            }
            result.push_back(temp);
        }
        int max = 0,start = 0,end = 0;
        for(int i = s.length() - 1 ; i >= 0; i--)
        {
            for(int j = i + 1; j < s.length(); j++)
            {
                if(s[i] == s[j])
                {
                    if(i + 1 == j)
                    {
                        result[i][j] = 1;
                        if((j-i) > max)
                        {
                            max = j - i;
                            start = i;
                            end = j;
                        }
                    }
                    else
                    {
                        result[i][j] = result[i+1][j-1];
                        if(result[i][j] == 1 && (j-i) > max)
                        {
                            max = j - i;
                            start = i;
                            end = j;
                        }
                    }
                }
            }
        }
        if(start == end) 
        {
            cout << s[start] << endl;
            return s.substr(start,1);
        }
        cout << s.substr(start,end-start+1) << endl;
        return  s.substr(start,end-start+1);
    }
};
int main()
{
    Solution s;
    while(1)
    {
        string input;
        cin >> input;
        s.longestPalindrome(input);
    }
    return 0;
}