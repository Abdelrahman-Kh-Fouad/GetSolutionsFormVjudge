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
    ll n ; cin>>n ;
    ll d ; cin>>d ; 
    vector<ll>arr(n);
    for(int i =0 ;i  < n; i++)cin>>arr[i];
    ll res = 0 ; 
    for(int i =0 ;i <  n-1 ;i++)
    {
        int tar = arr[i]+d;
        int ind = lower_bound(arr.begin()+i+1 ,arr.end() , tar) -arr.begin();
        if(ind == n )ind-- ; 
        if(arr[ind] > arr[i] && ind - i+1 >=3 && arr[ind] <= arr[i] + d )
            res += ((ind -i  )*(ind - i-1 ))/2;
        
    }

    cout<<res <<endl;
}   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}