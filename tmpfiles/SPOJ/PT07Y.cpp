#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
typedef long long ll;
typedef unsigned long long ull;

int dfs (vector<vector<int>>&adj ,  int node )
{
    int res =0 ; 
    for(int i : adj[node])
        res += dfs(adj , i);
    return res +1 ; 

}
bool solve()
{
    int n ; cin>>n ; 
    vector<vector<int>>adj(n+1 );
    int m ; cin>>m ; 
    int t , f ;
    int minn = INT_MAX ; 
    for(int i  =0 ;i  <m ;i++)
    {
        cin>>t >>f ;
        if(t > f )swap(t , f );
        adj[t].pb(f);
        minn = min ({minn , t ,f });
    }    
    return (dfs(adj , minn)== n );

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << (solve() ? "YES" : "NO")<<endl;
    
    return 0 ; 
}