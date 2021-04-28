#include <bits/stdc++.h>
using namespace std ;
vector<bool>used ;
vector<int>res;
int n ;
bool go(vector<vector<int>>& adj, int node,vector<bool>*track=new vector<bool>(n+1,0))
{
    bool sum =1;
    if (track->at(node)) return 0;
    else
    {

        for(auto i : adj[node])
        {
            track->operator[](node)=1;
            sum &=go(adj , i,track);
            track->operator [](node)=0;
        }
        return sum;
    }
}
void DFS(vector<vector<int>>&adj ,int node)
{

    if(used[node])
        return ;
    else
    {
        used[node]=1;
        for(auto i : adj[node])
            DFS(adj ,i);
        res.push_back(node);
    }
}
int main()
{
    int m ;
    while (cin>>n>>m , n||m)
    {
        res.clear();
        used.resize(n+1); used.assign(n+1 , 0);
        vector<vector<int>> adj(n+1);
        int a , b ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
        }

        bool sum = 1 ;
        for(int i=1 ; i <=n&&sum ;i++)
             sum &= go(adj , i );

        if (sum)
        {
            for(int i=1 ; i<=n ;i++)
                DFS(adj ,i);
            for(int i= res.size()-1 ; i >=0 ;i-- )
                cout<<res[i]<<endl;
        }
        else
            cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
