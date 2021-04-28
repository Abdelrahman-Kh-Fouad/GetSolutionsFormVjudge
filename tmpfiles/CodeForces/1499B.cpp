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
bool solve()
{
    string s ; cin>>s ; 
    for(int i =-1 ; i < sz(s) +1 ; i++)
    {
        bool f = 0 ;
        vector<int>tmp ; 
        for(int ind = 0; ind < sz(s) ;ind++) 
        {
            if(ind==i)f ^=1 ;
            if(s[ind] == '0'+(int)(!f)) tmp.pb(ind);
        }
        if(sz(tmp) ==1 )return 1 ; 
        bool res = 1 ; 
        for(int ind = 1 ;ind < sz(tmp) ; ind++) 
            if(!(tmp[ind-1]+1 <tmp[ind]))
                res &= 0 ;
        if(res )return 1 ;
    }
    return 0 ; 

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        cout<< (solve() ? "YES" :"NO")<<endl;;
    }
    return 0 ; 
}