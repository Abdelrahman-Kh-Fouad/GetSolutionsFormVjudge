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
void solve()
{

    int n ; cin>>n ; 
    ll arr[n];
    for(int i  =0 ;i  < n ; i++)
        cin>>arr[i];
    int c[2][n] ;
    for(int j =0 ;j < 2 ; j++)
        for(int i =0 ;i < n ; i++)
            cin>>c[j][i] ; 
    vector<vector<ll>>res (4 );
    for(int i =0 ;i < n ; i++)
    {
        res[c[0][i]].pb(arr[i]);
        if(c[0][i] != c[1][i])
            res[c[1][i]].pb(arr[i]);
    }
    for(int i = 0 ;i < 4 ; i++)
        sort(all(res[i])) , res[i].pb(-1) ;
    unordered_set<ll>ch ; 
    int ind[4]={0};
    int m ; cin>>m ; 
    while(m--)
    {
        int t ; cin>>t ; 
        ll tmp ; 
        while (ch.count(res[t][ind[t]]))
            ind[t]++;
        cout << res[t][ind[t]] << " ";
        if(res[t][ind[t]] !=-1)
            ch.insert(res[t][ind[t]]);
        
    }
    cout<<endl;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

        solve();
    
    return 0 ; 
}