#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    vector<pair<int,double>> a;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int index;
        double value;
        pair<int,double> temp;
        cin >> index >> value;
        temp.first = index;
        temp.second = value;
        a.push_back(temp);
    }
    cin >> num;
    double * result = new double[2005];
    for(int i = 0; i < 2005; i++) result[i] = 0;
    for(int i = 0; i < num; i++)
    {
        int index;
        double value;
        cin >> index >> value;
        for(int j = 0; j < a.size(); j++)
        {
            result[index+a[j].first] += (value*a[j].second);
        }
    }
    int n = 0;
    for(int i = 0; i < 2005; i++)
    {
        if(abs(result[i]) > 0.01) n++;
    }
    cout << n;
    for(int i = 2004 ; i >= 0; i--)
    {
        if(abs(result[i]) > 0.01)
        {
            cout << " " << i << " " << fixed << setprecision(1) << result[i];
        }
    }
    return 0;
}