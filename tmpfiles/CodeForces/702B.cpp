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
    vector<int>arr(n);
    unordered_map < int , int>  el;
    for(int i =0 ;i  <n ;i++)cin>>arr[i] , el[arr[i]]++;
    vector<ll> p;
    p.push_back(2);
    for(int i = 1; i <=31 ;i++)
        p.pb(p[i-1] *2 );
    set<pair<int,int>>ch;
    unordered_set<int>used ; 
    ll res =0 ;
    for(auto power : p )
    {
        for(auto i : el)
        {
            if(i.ff >= power )
                continue;
            int sec = power - i.ff ;
            if(el.count(sec) && !ch.count({i.ff ,sec}) && !ch.count({sec , i.ff})  )
            {
                ch.insert({i.ff , sec});
                used.insert(i.ff);
                if(i.ff == sec)
                    res +=((ull)el[sec ] * (ull)(el[sec]-1))/2 ;
                else 
                    res +=el[sec] * i.ss ;
            }
        } 
    }
    // (n !)/ (n -2 )! * 2 
    cout<<res<<endl;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}