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
double q , p ,r , s , t , u ;

double eq(double x )
{
    return p * exp(-x) + q*sin(x) + r*cos(x) +s*tan(x) + t *(x*x) + u ;
}
void solve()
{
    double l = 0.0 , h = 1.0 ;
    double mid ;
     
    while(h -l >1e-9)
    {
        mid = (l + h) /2.0 ;
        double tmp = eq(mid); 
        if (tmp < 0 )
            h= mid ;
        else l = mid ;
    }
    //printf("%0.4f %0.4f\n" ,mid , eq(mid));
    if(fabs(eq(mid)) <=1e-4)
        printf("%0.4f\n" , mid);
    else 
        cout<<"No solution"<<endl;
   
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> p >>q >> r >>s >> t >>u )
    {
        solve();
    }
    return 0 ; 
}