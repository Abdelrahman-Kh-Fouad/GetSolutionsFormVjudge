#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.ff << ", " << p.ss << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i =0; i< sz(v) ; i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}
typedef long long ll;
typedef unsigned long long ull;
int parent[1001];
vector<int>PathToRoot(int node )
{   
    int cur = node ;
    vector<int>path ;
    while(cur !=-1)
    {
        path.pb(cur);
        cur =parent[cur];
    }
    return path;
}
void solve()
{
    int n ; cin>>n ;
    memset(parent , -1 ,sizeof parent);
    for(int i =0; i  <n ;i++)
    {
        int m ; cin>>m ;
        int tt ;  
        for(int j =0 ; j < m ;j++)
            cin>>tt , parent[tt-1]=i;
    }
    int q ; cin>>q ; 
    while(q--)
    {
        int l ,r ; 
        cin>> l >> r ; 
        vector<int>path1 = PathToRoot(l-1) ,path2 = PathToRoot(r-1);
        
        set<int>inpath2(all(path2));
        int res = -1; 
        for(int i = 0 ; i <sz(path1) ; i+=1)
            if(inpath2.count(path1[i]))
            {
                res = path1[i];
                break;
            }

        cout <<res +1<<endl;
        
    }
}   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}