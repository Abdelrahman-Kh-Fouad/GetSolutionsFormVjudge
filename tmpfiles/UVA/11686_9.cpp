#include <bits/stdc++.h>
using namespace std;
vector<bool>used ;
vector<int>res;

bool DFS(vector<vector<int>>&adj ,int node,set<int>* track=new set<int>{} )
{
    bool sum = 1;
    if (track->count(node))
        return 0;
    if (used[node])
        return 1;

        (track)->insert(1);
        used[node]=1;
        for(auto i : adj[node])
            sum &=DFS(adj ,i,track);
        res.push_back(node);


    return sum;
}
int main()
{
    int n ,m ;
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
            if (!used[i])sum&=DFS(adj , i );

        if (sum)
        {
            for(int i= res.size()-1 ; i >=0 ;i-- )
                cout<<res[i]<<endl;
        }
        else
            cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
