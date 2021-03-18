#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string a,b;
    int tag,radix;
    cin >> a >> b >> tag >> radix;
    long long int num = 0;
    string given,obj;
    if(tag == 1)
    {
        given = a;
        obj = b;
    }
    else
    {
        given = b;
        obj = a;
    }
    for(int j = 1,i = given.length() - 1; i >= 0; i--)
    {
        int temp = given[i] - '0';
        if(temp > 9)
        {
            temp = given[i] - 'a' + 10;
        }
        num += j*temp;
        j *= radix;
    }
    vector<int> objnum;
    long long int max = 0;
    for(int i = 0; i < obj.length(); i++)
    {
        long long int temp = obj[i] - '0';
        if(temp > 9)
        {
            temp = obj[i] - 'a' + 10;
        }
        if(temp > max) max = temp;
        objnum.push_back(temp);
    }
    long long int left = max + 1, right = num + 1;
    long long int min_radix = -1;
    while(left <= right)
    {
        long long int mid = (left + right)/2;
        long long int result = 0;
        for(long long int exp = 1,j = objnum.size() - 1; j >= 0; j--)
        {
            result += exp * objnum[j];
            exp *= mid;
        }
        if(result == num) 
        {
            right = mid - 1;
            if(min_radix < 0) min_radix = mid;
            else if(min_radix > mid) min_radix = mid;
        }
        else if(result > num || result < 0) 
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    if(min_radix < 0) cout << "Impossible";
    else cout << min_radix;
    return 0;
}