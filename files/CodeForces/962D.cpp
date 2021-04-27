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
    map<ll,vector<int>>mp ; 
    for(int i =0 ;i  <n ;i++)cin>>arr[i] , mp[arr[i]].pb(i);
    vector<ll>res(arr ,arr+ n ) ;
    int szz = n ; 
    for(map<ll,vector<int>>::iterator i = mp.begin() ; i != mp.end() ;i++)
    {
        sort(all(i->ss));
        for(int j =1 ; j < sz(i->ss ) ;j+=2)
        {
            res[i->ss[j-1]] =-1 ;
            szz-- ; 
            mp[i->ff*2 ].pb(i->ss[j]);

            res [i->ss[j]]=i->ff *2 ;
        }
    }
    cout<<szz<<endl;
    for(ll &i:res )if(i> 0 )cout<<i<<" ";
    cout<<endl;   
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    

    solve();
    return 0 ; 
}