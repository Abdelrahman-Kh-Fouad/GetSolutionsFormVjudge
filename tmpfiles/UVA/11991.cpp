#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , m ;
    cin>>n>>m;
    int tmp;
    vector<vector<int>>adj (n+1);
    for(int i=1 ;i <=n ;i++)cin>>tmp,adj[tmp].push_back(i);
    int k , v ;
    for(int i =0 ;i < m ;i++)
    {
        cin>>k>>v;
        if(adj[v].size()<k)
          cout<<0<<endl;
        else
            cout<<adj[v][k-1]<<endl;
    }
    return 0;
}
