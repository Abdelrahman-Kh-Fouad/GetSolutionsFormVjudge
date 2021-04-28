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
int k=1 ; 
string s ; 
void solve()
{       
    getline(cin ,s );
    unordered_map<int,int>mp ; 
    for(auto i : s ) mp[i]++;
    vector<int>dup ; 
    dup.pb(1);
    for(auto &i : mp)if(i.ss > 1 )dup.pb(i.ss);
    sort(all(dup) , greater<int>());
    ull res =1 ; 
    for(ll i = sz(s) ; i >dup.front() ; i--)
        res *=i ;   
    for(int i =1 ;i < sz(dup) ;i++)
        res /=dup[i];
    printf("Data set %d: %d\n" , k++ , res );

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    getline(cin ,s );
    while(t--)
    {
        solve();
    }
    return 0 ; 
}