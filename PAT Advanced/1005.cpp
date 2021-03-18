#include<iostream>
#include<string>
using namespace std;
int main()
{
    string input;
    cin >> input;
    int sum = 0;
    for(int i = 0; i < input.length(); i++)
    {
        int temp = input[i] - '0';
        sum += temp;
    }
    string output = to_string(sum);
    int i = 0;
    for( ;i < output.length()-1; i++)
    {
        int temp = output[i] - '0';
        switch (temp)
        {
        case 0:
            cout << "zero" << " ";
            break;
        case 1:
            cout << "one" << " ";
            break;
        case 2:
            cout << "two" << " ";
            break;
        case 3:
            cout << "three" << " ";
            break;
        case 4:
            cout << "four" << " ";
            break;
        case 5:
            cout << "five" << " ";
            break;
        case 6:
            cout << "six" << " ";
            break;
        case 7:
            cout << "seven" << " ";
            break;
        case 8:
            cout << "eight" << " ";
            break;
        case 9:
            cout << "nine" << " ";
            break;
        default:
            break;
        }
    }
    int temp = output[i] - '0';
    switch (temp)
    {
        case 0:
            cout << "zero";
            break;
        case 1:
            cout << "one";
            break;
        case 2:
            cout << "two";
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        case 6:
            cout << "six";
            break;
        case 7:
            cout << "seven";
            break;
        case 8:
            cout << "eight";
            break;
        case 9:
            cout << "nine" ;
            break;
        default:
            break;
        }
    return 0;
}