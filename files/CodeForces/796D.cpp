#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<bool>used ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , m , k ; cin>> n>>m >> k ;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>police(m);
    used.assign(n+1 , 0);
    queue <pair<int,int>>q; 
    int f , t ;
    for(int i =0; i <m ;i++)
        cin>> police[i] , q.push({police[i] , k}) , used[police[i]]=1;
    for(int i=0 ;i < n-1 ;i++)
    {
        cin>> f >>t ; 
        adj[f].push_back({t , i+1});
        adj[t].push_back({f , i+1});
    }
    set<int>token ; 
    while (!q.empty())
    {
        pair<int,int>cur = q.front();
        q.pop();
        for(auto &i :adj[cur.ff])
            if(!used[i.ff]&& cur.ss -1 >= 0)
                used [i.ff] =1 , q.push({i.ff , cur.ss -1 }) , token.insert(i.ss);    
    }
    cout<< n-1 - sz(token)<<endl;
    for(int i =1 ;i <= n-1 ;i++)
        if(!token.count(i))
            cout<< i <<" ";
        cout<<endl;

    return 0 ; 
}