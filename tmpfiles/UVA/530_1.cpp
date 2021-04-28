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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

unordered_map<pair<ull,ull>, ull ,hash_pair>memo ; 
ull C(ull n, ll k) {
    if(k ==0 )
        return 1;
    if(n <k )
        return 0 ;
    if(memo.count({n ,k }))
        return memo[{n , k }];
    return memo[{n , k }]= C(n -1 , k  ) + C(n -1 , k-1 );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll  n ,k ; 
    while(cin>>n >>k )
    {
        if(k > n/2 )
            k -= n/2 ;
        double  res =1 ; 
        for(ll i =0 ; i< k ; i++)
            res =res * (double)(n-i ) /(i+1) ;
        printf("%lld\n",(ull)res) ;
    }
    
    return 0 ; 
}