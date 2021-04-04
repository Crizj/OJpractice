#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
class Solution 
{
public:
    string truncateSentence(string s, int k) 
    {
        vector<string> result;
        istringstream is(s);
        string temp;
        while(is >> temp)
        {
            result.push_back(temp);
            //cout << temp;
        }
        string re;
        if(!result.empty()) re.append(result[0]);
        for(int i = 1; i < k; i++)
        {
            re.append(" "+ result[i]);
        }
        // int last = 0;
        // for(int i = 0; i < k; i++) 
        // {
        //     int id = s.find(' ');
        //     string temp = s.substr(last,id);
        //     result.push_back(temp);
        //     cout << temp << endl;
        //     last = id;
        //     s = s.substr(id+1,s.size()-1);
        // }
        //for(int )
        cout << re << endl;
        return re;
    }
};
int main()
{
    while(1)
    {
        Solution temp;
        temp.truncateSentence("Hello how are you Contestant",3);
    }
    return 0;
}