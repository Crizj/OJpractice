#include<iostream>
#include<string>
using namespace std;
class Solution 
{
public:
    bool halvesAreAlike(string s) 
    {
        int result = 0;
        int i = 0;
        for(; i < (s.length()/2); i++)
        {
            switch(s[i])
            {
                case 'a': result++;break;
                case 'e': result++;break;
                case 'i': result++;break;
                case 'o': result++;break;
                case 'u': result++;break;
                case 'A': result++;break;
                case 'E': result++;break;
                case 'I': result++;break;
                case 'O': result++;break;
                case 'U': result++;break;
                default:break;
            }
        }
        for(; i < s.length(); i++)
        {
            switch(s[i])
            {
                case 'a': result--;break;
                case 'e': result--;break;
                case 'i': result--;break;
                case 'o': result--;break;
                case 'u': result--;break;
                case 'A': result--;break;
                case 'E': result--;break;
                case 'I': result--;break;
                case 'O': result--;break;
                case 'U': result--;break;
                default:break;
            }
        }
        if(result == 0) return true;
        return false;
    }
};

int main()
{
    while(1)
    {
        string in;
        cin >> in;
        Solution s;
        if(s.halvesAreAlike(in)) cout << "true" << endl;
        else cout << "false" << endl;
    }
}