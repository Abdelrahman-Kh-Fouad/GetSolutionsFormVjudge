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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll  n ,k ; 
    while(cin>> n>>k && (n||k) )
    {
        if(k > n /2 )
            k = n- k ;
        ull res =1 ; 
        for(ll i =0 ;i <  k ;i++)
        {
            res *=n-i ;
            res /=(i+1)  ;
        }       
        printf("%lld things taken %lld at a time is %lld exactly.\n" , n , k , res );
    }
    
    return 0 ; 
}