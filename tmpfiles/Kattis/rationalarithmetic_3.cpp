#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 

typedef long long ll;
typedef unsigned long long ull;

void solve()
{   
    ll x1 ,y1 , x2 ,y2 ; 
    char op ;
    cin>>x1 >> y1 >> op >> x2 >> y2;
    pair<ll,ll>res ; 
    if(op =='*')
        res.ff = x1 *x2 , res.ss =y1*y2;
    else if (op=='+')
        res.ff = x1 * y2 + x2 * y1 , res.ss = y1 * y2 ;
    else if(op=='/')
        res.ff =x1 *y2 , res.ss = y1 * x2 ; 
    else if(op=='-')
        res.ff = x1 * y2 -(x2 * y1) , res.ss = y1 * y2 ;
    if(res.ff < 0 && res.ss >= 0 || res.ff >=0 && res.ss< 0) printf("-");
    ll g = __gcd(abs(res.ff) , abs(res.ss));
    printf("%d / %d\n" , abs(res.ff) / g , abs(res.ss) /g );
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}