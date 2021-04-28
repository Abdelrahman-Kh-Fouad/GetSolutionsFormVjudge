#include <bits/stdc++.h>
using namespace std ;
set<int >used ;
vector<int>element;
void dfs1(vector<vector<int>>&adj , int node )
{
    used.insert(node);
    for(auto i : adj[node])
        if(!used.count(i))
            dfs1(adj , i);
    element.push_back(node);
}
void dfs2(vector<vector<int>>&adj , int node )
{
    used.insert(node);
    for(auto i : adj[node])
        if(!used.count(i))
            dfs2(adj,i);
}
int main() {
    int n ,m ;
    while(cin>>n>>m , n!=0 && m!=0)
    {
        vector<vector<int>> adj(n+1) ,adjR(n+1);
        int from , to , val ;
        for (int i =0 ;i < m ;i++)
        {
            cin>>from>>to>>val;
            if(val==1)
                adj[from].push_back(to) ;
            else
                adj[from].push_back(to),
                adj[to].push_back(from);

        }
        for(int i =1 ; i <= n ;i++)
            for(auto j : adj[i])
                adjR[j].push_back(i);
        /*for(int i =1 ; i <= n ;i++)
        {
            cout<<i<<" - >";
            for(auto j : adj[i])
                cout<<j<<" ";
            cout<<endl;
        }*/
        element.clear(); used.clear();
        for(int i =1 ;i <=n ;i++)
            dfs1(adj , i );
        used.clear();
        int cnt =0;
        reverse(element.begin() , element.end());
        for (auto i : element)
            if (!used.count(i))
                cnt++,dfs2(adj , i );

        if(cnt>1)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}

