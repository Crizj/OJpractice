#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if(digits.empty()) return result;
        vector<vector<char>> m(8,vector<char>(3,'a'));
        m[0][1] = 'b',m[0][2] = 'c';
        m[1][0] = 'd',m[1][1] = 'e';m[1][2] = 'f';
        m[2][0] = 'g',m[2][1] = 'h',m[2][2] = 'i';
        m[3][0] = 'j',m[3][1] = 'k',m[3][2] = 'l';
        m[4][0] = 'm';m[4][1] = 'n',m[4][2] = 'o';
        m[5][0] = 'p',m[5][1] = 'q';m[5][2] = 'r'; m[5].push_back('s');
        m[6][0] = 't',m[6][1] = 'u';m[6][2] = 'v';
        m[7][0] = 'w',m[7][1] = 'x';m[7][2] = 'y'; m[7].push_back('z');
        result.push_back("");
        for(int i = 0; i < digits.length(); i++)
        {
            vector<string> tempvec;
            while(!result.empty())
            {
                string temp = result.back();
                result.pop_back();
                for(int j = 0; j < m[digits[i]-'2'].size(); j++)
                {
                    tempvec.push_back(temp+m[digits[i]-'2'][j]);
                }
            }
            result = tempvec;
        }
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
        }
        return result;
    }
};

int main()
{
    while(1)
    {
        string in;
        cin >> in;
        Solution s;
        s.letterCombinations(in);
    }
    return 0;
}