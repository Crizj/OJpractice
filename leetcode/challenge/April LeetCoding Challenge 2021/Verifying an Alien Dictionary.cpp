#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Solution 
{
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        for(int i = 0; i+1 < words.size(); i++)
        {
            string a = words[i], b = words[i+1];
            int j = 0;
            for(; j < a.length() && j < b.length(); j++)
            {
                if(order.find_first_of(a[j]) > order.find_first_of(b[j])) return false;
                else if(order.find_first_of(a[j]) < order.find_first_of(b[j])) break;
            }
            if(j == b.length() && a.length() > b.length()) return false; 
        }
        return true;
    }
};

int main()
{
    vector<string> in = {"app","apple"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    Solution s;
    if(s.isAlienSorted(in,order)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}