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

class stat {
public :
    ll up , down ; 
    stat():up(0),down(0){}
    stat(ll up ,ll down):up(up),down(down){}

    stat operator+ (const stat &other){
        return stat(other.up + up , other.down +down);
    }
    double val (){
        return (double)up/down;
    }

};
void solve(int m , int n ){
    string s ="";
    stat cur(1, 1) , r(1 , 0) , l (0 ,1);
    while(cur.up != m && cur.down != n){
       
        if(cur.val() > (double)m/n){
            r = cur ; 
            cur = l+ r ;
            s+="L";
        }
        else {
            l= cur ; 
            cur = l+ r ;
            s+="R";
        } 
       
    }
    cout <<s <<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m , n ; 
    while(cin>> m >>n && n>1  && m  >1 )
    {
        solve(m ,n );
    }
    return 0 ; 
}