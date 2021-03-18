#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class mytime
{
private:
    int hour,min,sec;
public:
    mytime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }
    void ctime(string t)
    {
        stringstream s;
        s << t.substr(0,2) << " " << t.substr(3,2) << " " << t.substr(6,2);
        s >> hour >> min >> sec;
        //cout << hour << " " << min << " " << sec << endl;
    }
    mytime()
    {
        hour = min = sec = 0;
    }
    bool operator > (mytime & one);
    bool operator < (mytime & one);
};

bool mytime::operator>(mytime & one)
{
    if(hour > one.hour) return true;
    else if(hour < one.hour) return false;
    else if(min > one.min) return true;
    else if(min < one.min) return false;
    else if(sec > one.sec) return true;
    else if(sec < one.sec) return false;
    return false;
}

bool mytime::operator<(mytime & one)
{
    if(hour > one.hour) return false;
    else if(hour < one.hour) return true;
    else if(min > one.min) return false;
    else if(min < one.min) return true;
    else if(sec > one.sec) return false;
    else if(sec < one.sec) return true;
    return false;
}

class record
{
protected:
    string id;
public:
    mytime start,end;
    friend istream & operator>> (istream & is,record & c);
    record(){}
    void output()
    {
        cout << id;
    }
};

istream & operator>>( istream & is, record & c)
{
    is >> c.id;
    //cout << c.id << " ";
    string start_time,end_time;
    cin >> start_time >> end_time;
    c.start.ctime(start_time);
    c.end.ctime(end_time);
    return is;
}

int main()
{
    int num;
    cin >> num;
    record * rec = new record[num];
    for(int i = 0; i < num; i++)
    {
        cin >> rec[i];
    }
    int min = 0, max = 0;
    mytime start = mytime(99,99,99);
    mytime end = mytime(0,0,0);
    for(int i = 0; i < num; i++)
    {
        if(rec[i].start < start)
        {
            start = rec[i].start;
            min = i;
        }
        if(rec[i].end > end)
        {
            end = rec[i].end;
            max = i;
        }
    }
    rec[min].output();
    cout << " ";
    rec[max].output();
    return 0;
}