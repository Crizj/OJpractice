#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    while(1)
    {
    double a[1001];
    for(int i = 0; i < 1001; i++) a[i] = 0;
    int ka,kb;
    cin >> ka;
    for(int i = 0 ; i < ka;i ++)
    {
        int exp;
        double coe;
        cin >> exp >> coe;
        a[exp] = coe;
    }
    cin >> kb;
    for(int i = 0 ; i < kb;i ++)
    {
        int exp;
        double coe;
        cin >> exp >> coe;
        a[exp] += coe;
    }
    int num = 0;
    for(int i = 0; i < 1001; i++)
    {
        if(a[i] != 0) num++;
    }
    cout << num;
    for(int i = 1000;i >= 0; i--)
    {
        if(a[i] != 0) cout << fixed << " " << i << " " << setprecision(1) << a[i]; 
    }
    }
    return 0;
}