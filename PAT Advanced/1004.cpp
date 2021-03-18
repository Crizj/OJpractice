#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node
{
private:
    int id;
public:
    vector<int> child;
    node()
    {
        id = 0;
    }
    void c_id(int iid)
    {
        id = iid;
    }
    void push_back(int chi)
    {
        child.push_back(chi);
    }
};
int main()
{
    node * root = NULL;
    int num_of_node,num_none_leaf;
    cin >> num_of_node >> num_none_leaf;
    root = new node[num_of_node+1];
    for(int i = 0 ; i < num_none_leaf; i++)
    {
        int id,num_of_child;
        cin >> id >> num_of_child;
        root[id].c_id(id);
        int temp;
        for(int j = 0; j < num_of_child; j++)
        {
            cin >> temp;
            root[id].push_back(temp);
        }
    }
    queue<int> father;
    queue<int> child;
    father.push(1);
    while((father.empty() == false) || (child.empty() == false))
    {
        int num = 0;
        while(!father.empty())
        {
            int id = father.front();
            father.pop();
            if(root[id].child.empty())
            {
                num++;
            }
            else
            {
                for(int i = 0; i < root[id].child.size(); i++)
                {
                    child.push(root[id].child[i]);
                }
            }
        }
        father = child;
        while(!child.empty()) child.pop();
        if(father.empty())
        {
            cout << num;
        }
        else cout << num << " ";
    }
    return 0;
}