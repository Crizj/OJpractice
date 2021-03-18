#include<iostream>
#include<vector>
#include<set>
using namespace std;
enum Color{black,white,gray};
struct City
{
    Color color;
    int back;
};
struct Edge
{
    int cost,status;
    int first,second;
};
int dfs(int current, vector<int> & result, City * city, Edge ** map,int num_city,int time, int parent)
{
    city[current].color = gray;
    time++;
    city[current].back = time;
    int n = 0;
    for(int i = 0; i < num_city; i++)
    {   
        if(i != current && map[current][i].status == 1)
        {
            if(city[i].color == white)
            {
                int back = dfs(i,result,city,map,num_city,time,current);
                n++;
                if(back >= city[current].back && current != 0)
                {
                    result.push_back(current);
                }
                else city[current].back = back;
            }
            else if(i != parent && city[i].color == gray)
            {
                if(city[current].back >= city[i].back) city[current].back = city[i].back;
            }
        }
    }
    city[current].color = black;
    if(current == 0 && n >= 2) result.push_back(current);
    return city[current].back;
}

void dfs_cost(int current, City * city, Edge ** map,int num_city,set<int> & result)
{
    result.insert(current);
    city[current].color = gray;
    for(int i = 0; i < num_city; i++)
    {   
        if(i != current && map[current][i].status == 1 && city[i].color == white)
        {
            dfs_cost(i,city,map,num_city,result);
        }
    }
    city[current].color = black;
}

int cost(Edge ** map,int obj, int num_city,vector<Edge> choice)
{
    set<int> a,b;
    for(int i = 0; i < num_city; i++)
    {
        if(map[obj][i].status == 1)
        {
            map[obj][i].status = -2;
            map[i][obj].status = -2;
        }
    }
    City * city = new City[num_city];
    for(int i = 0; i < num_city; i++)
    {
        city[i].back = 99999;
        city[i].color = white;
    }
    city[obj].color = black;
    for(int i = 0; i < num_city; i++)
    {
        if(i != obj && city[i].color == white)
        {
            dfs_cost(i,city,map,num_city,a);
            break;
        }
    }
    for(int i = 0; i < num_city; i++)
    {
        if(i != obj && city[i].color == white)
        {
            dfs_cost(i,city,map,num_city,b);
            break;
        }
    }
    int min = 999999999;
    for(int i = 0; i < choice.size(); i++)
    {
        if((a.find(choice[i].first) != a.end()) && (b.find(choice[i].second) != b.end()))
        {
            if(choice[i].cost < min) min = choice[i].cost;
        }
        else if((a.find(choice[i].second) != a.end()) && (b.find(choice[i].first) != b.end()))
        {
            if(choice[i].cost < min) min = choice[i].cost;
        }
    }
    for(int i = 0; i < num_city; i++)
    {
        if(map[obj][i].status == -2)
        {
            map[obj][i].status = 1;
            map[i][obj].status = 1;
        }
    }
    return min;
}

int main()
{
    int num_city,num_edge;
    cin >> num_city >> num_edge;
    Edge ** map = new Edge*[num_city];
    for(int i = 0; i < num_city; i++)
    {
        map[i] = new Edge[num_city];
    }
    for(int i = 0; i < num_city; i++)
    {
        for(int j = 0; j < num_city; j++)
        {
            map[i][j].cost = 0;
            map[i][j].status = -1; //-1 : do not exist
        }
    }
    vector<Edge> choice;
    for(int i = 0; i < num_edge; i++)
    {
        int first,second,val,status;
        cin >> first >> second >> val >> status;
        map[first-1][second-1].cost = val;
        map[first-1][second-1].status = status;
        map[first-1][second-1].first = first;
        map[first-1][second-1].second = second;
        map[second-1][first-1].cost = val;
        map[second-1][first-1].status = status;
        map[second-1][first-1].first = first;
        map[second-1][first-1].second = second;
        if(status == 0)
        {   
            Edge temp;
            temp.cost = val,temp.first = first,temp.second = second,temp.status = status;
            choice.push_back(temp);
        }
    }
    //step1: 寻找割点 dfs搜索
    vector<int> result;
    City * city = new City[num_city];
    for(int i = 0; i < num_city; i++)
    {
        city[i].back = 99999;
        city[i].color = white;
    }
    dfs(0,result,city,map,num_city,0,-1);
    // for(int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] + 1 << " ";
    // }
    // cout << endl;
    if(result.empty()) 
    {
        cout << 0;
        return 0;
    }
    int min = 999999999;
    vector<int> res;
    for(int i = 0; i < result.size(); i++)
    {
        //考察去掉城市i之后，连接两个连通分量需要的代价
        int temp = cost(map,result[i],num_city,choice);
        //cout << temp << endl;
        if(temp < min) 
        {
            res.clear();
            min = temp;
            res.push_back(result[i]);
        }
        else if(temp == min)
        {
            res.push_back(result[i]);
        }
    }
    //输出结果要+1
    cout << res[res.size()-1] + 1;
    for(int i = res.size() - 2; i >= 0; i--)
    {
        cout << " " << res[i] + 1;
    }
    return 0;
}