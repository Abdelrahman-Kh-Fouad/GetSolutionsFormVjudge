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







int N, W ;
ll w[101];
int v[101];
map<pair<int,ll>,ll>memo ;
int dp(int ind  = 0, ll sum = 0 )
{
    if(sum>W) return -1e9;
    if(ind == N )return 0;

    if(memo.count({ind , sum}))
        return memo[{ind ,sum }];
    ll &stat = memo[{ind ,sum}]; 
    return stat =max(dp(ind+1 , sum) , dp(ind+1 , sum +w[ind])+v[ind]);

}
void solve()
{
    cin>>N>>W; 
    for(int i =0 ;i  <N;i++)cin>>w[i]>>v[i];
    cout<<dp()<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


        solve();
    
    return 0 ; 
}