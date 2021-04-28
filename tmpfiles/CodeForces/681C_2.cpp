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
    string com ; int tar ;
    multiset<int>ch ;
    stringstream res("") ;
    for(int i =0  ;i  <n ;i++)
    {
        
        cin>>com;
        if(com=="insert")
        {
            cin>> tar ;
            ch.insert(tar);
            res<<com <<" "<<tar<<endl;
        }
        else if(com=="removeMin")
            ch.erase(ch.begin()) ,res<< com <<endl;
        else 
        {
            cin>> tar ; 
            if(tar != *ch.begin() || !ch.empty())
            {
                while(!ch.empty() &&  *ch.begin() < tar)
                    ch.erase(ch.begin()) , res<<"removeMin"<<endl;
                if((ch.empty())||(!ch.empty() && *ch.begin() != tar))
                    ch.insert(tar),res<<"insert "<<tar<<endl;
            }
            res<<com<<" "<<tar<<endl;
        }
    }
    int cnt =0 ;
    for(auto i : res.str())if(i=='\n')cnt++;
    cout<<cnt <<"\n"<<res.str();

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
    return 0 ; 
}