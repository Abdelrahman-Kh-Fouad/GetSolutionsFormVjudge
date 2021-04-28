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

bool check(map<int,vector<vector<int>>>&adj , int c,int  u ,int v )
{
    int n = sz((adj.begin()->ss));
    bool used [n]={0};
    queue<int>q;
    q.push(u);
    while (!q.empty())
    {
        int cur = q.front();
        if(cur==v)return 1;
        q.pop();
        for (int &i : adj[c][cur])
            if(!used[i])
                q.push(i) ,used[i]=1;
    }
    return 0 ;
}
void solve()
{
    int n , m;
    cin>>n >>m ;  
    map<int,vector<vector<int>>>adj;
    int f ,t ,c ;
    for(int i =0 ;i < m ; i++)
    {
        cin>> f >> t >> c;
        if(!adj.count(c))
            adj[c].assign(n +1 ,vector<int>());
        adj[c][f].pb(t);
        adj[c][t].pb(f);
    }
    int q ; cin>>q ; 
    while(q--)
    {
        int u , v ; 
        cin>> u >>v;
        int cnt =0 ;
        for(auto &it : adj)
            cnt +=check(adj , it.ff , u ,v );
        cout<<cnt<<endl;

    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in" ,"r" ,stdin);
    solve();
    return 0 ; 
}