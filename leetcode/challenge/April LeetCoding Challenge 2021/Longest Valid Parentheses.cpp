#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int num = 0, m = 0;
        vector<int> result(s.length(),0);
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == ')' && s[i-1] == '(')
            {
                int temp = (i-2>=0)?result[i-2]:0;
                result[i] = 2 + temp;
            }
            else if(s[i] == ')' && s[i-1] == ')' && i-result[i-1]-1 >= 0 && s[i-result[i-1]-1] == '(' )
            {
                int temp = (i-result[i-1]-2 >= 0)?result[i-result[i-1]-2]:0;
                result[i] = 2 + result[i-1] + temp;
            }
            m = max(m,result[i]);
        }
        cout << m << endl;
        return m;
    }
};

int main()
{
    while(1)
    {
        string s;
        cin >> s;
        Solution temp;
        temp.longestValidParentheses(s);
    }
    return 0;
}