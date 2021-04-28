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
    unordered_map<ll ,vector<int>> el;
    vector<ll>p;
    p.pb(2);
    for(int i =1 ;i  <=41 ;i++)p.pb(2 * p[i-1]);
    int n ; cin>>n ; 
    vector<int>arr(n);
    for(int i =0 ;i  <n ;i++)cin>>arr[i] ,el[arr[i]].pb(i);
    int cnt =0 ;
    for(int i =0 ;i  <n-1 ;i++)
    {
        int ind = upper_bound(all(p) , arr[i])-p.begin();
        if(ind == sz(p))ind--;
        ll power = p[ind];
        int sec = power - arr[i];
        if(el.count(sec))
        {
            vector<int>&v = el[sec];
            ind =upper_bound(all(v) , i )-v.begin();
            if(ind==sz(v))ind--;
            if(v[ind] <=i)continue;
            cnt+=sz(v) - ind;
        }
        
    }
    cout<<cnt<<endl;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
      solve();
    
    return 0 ; 
}