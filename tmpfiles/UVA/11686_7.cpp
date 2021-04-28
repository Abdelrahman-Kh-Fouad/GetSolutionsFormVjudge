#include <bits/stdc++.h>
using namespace std;
vector<bool>used;
vector<int >res ;
void DFS(vector<vector<int>>&adj ,int node )
{
    if (!used[node])
    {
        used[node]=1;
        for(auto  i : adj[node])
            DFS(adj , i);
        res.push_back(node);
    }

}
int main()
{
    int n ,m ;
    while (cin>>n>>m , n||m)
    {

        vector<vector<int>> adj(n+1);
        used.resize(n+1);used.assign(n+1,0);
        res.clear();
        int a , b ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for(int i=1 ; i <=n ;i++)
            DFS(adj , i );
        reverse(res.begin() , res.end());
        for(auto i : res )
            cout<<i<<endl;

    }
    return 0;
}
