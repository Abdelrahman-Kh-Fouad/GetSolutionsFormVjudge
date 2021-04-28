#include <bits/stdc++.h>
using namespace std;
vector<int>used;
vector<bool>in_res;
vector<int >res ;
bool DFS(vector<vector<int>>&adj ,int node)
{
    bool sum = 1;
    if (!used[node])
    {
        used[node]=1;
        for(auto  i : adj[node])
            sum &=DFS(adj , i);
        if (!in_res[node])
            res.push_back(node), in_res[node]=1;
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

        vector<vector<int>> adj(n+1);
        used.resize(n+1);used.assign(n+1,0);
        in_res.resize(n+1);in_res.assign(n+1,0);
        res.clear();
        int a , b ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
        }
        bool sum = 1 ;
        for(int i=1 ; i <=n ;i++)
        {
            used.clear();
            used.assign(n,0);
            if (!in_res[i])sum&=DFS(adj , i );
        }
        if (sum)
        {
            reverse(res.begin() , res.end());
            for(auto i : res )
                cout<<i<<endl;
        }
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
