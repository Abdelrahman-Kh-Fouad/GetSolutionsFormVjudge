#include <bits/stdc++.h>
using namespace std;
vector<bool>used ;
vector<bool>in_track;
vector<int>res;
bool DFS(vector<vector<int>>&adj ,int node)
{
    bool sum = 1;
    if (used[node])
        return 1 ;
    if (!in_track[node])
    {
        in_track[node]=1;

        for(auto i : adj[node])
            sum &=DFS(adj , i);
        res.push_back(node);
    }
    else
        return 0 ;
    return sum;
}
int main()
{
    int n ,m ;
    while (cin>>n>>m , n||m)
    {
        res.clear();
        used.resize(n+1); used.assign(n+1 , 0);
        in_track.resize(n+1);

        vector<vector<int>> adj(n+1);
        int a , b ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
        }
        bool sum = 1 ;
        for(int i=1 ; i <=n&&sum ;i++)
        {
            in_track.assign(n+1,0);
            sum&=DFS(adj , i );
        }
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
