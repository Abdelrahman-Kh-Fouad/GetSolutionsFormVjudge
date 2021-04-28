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
bool cmp(pair<int,int>&x , pair<int,int>&y){return(x.ss == y.ss)? x.ff > y.ff : x.ss > y.ss ;}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ; cin>>n ;
    int s ; cin>>s ; 
    map<char , map<int ,int >>mp;
    char b ; int t ,f ;
    for(int i =0 ;i  <n ;i++)
        cin>> b >>t >>f ,mp[b][t]+=f;
    
    vector<pair<int,int>>ss(all(mp['S'])) ;
    vector<pair<int,int>>bb(all(mp['B'])) ;
    sort(all(ss) , cmp);
    sort(all(bb) , cmp);
    for(int i=0 ;i < s && i<sz(ss);i++)
        cout<< 'S'<<" "<<ss[i].ff <<" "<<ss[i].ss<<endl; 
    for(int i=0 ;i < s && i<sz(bb);i++)
        cout<< 'B'<<" "<<bb[i].ff<<" "<<bb[i].ss<<endl;
    
    
    return 0 ; 
}