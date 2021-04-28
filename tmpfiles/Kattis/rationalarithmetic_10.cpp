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
pair<ll,ll> sum (ll x1 ,ll y1 ,ll x2 ,ll y2  )
{
    return {y1 * x2 + x1 * y2  , y1 * y2 };
}
pair<ll,ll>prod(ll x1 ,ll y1 ,ll x2 ,ll y2)
{
    return {x1 *x2 , y1 *y2 };
}
pair<ll,ll> opt(pair<ll,ll>x )
{
    if(x.ff == 0 )
        return x ; 
    ll tmp = __gcd(abs(x.ff) , abs(x.ss) );
    x.ff /=tmp , x.ss/=tmp;
    return x ; 
}
void solve()
{   
    ll x1 ,y1 , x2 ,y2 ; 
    char op ;
    cin>>x1 >> y1 >> op >> x2 >> y2;
    pair<ll,ll>res ; 
    if(op =='*')
        res = opt(prod(x1 ,y1 ,x2 ,y2 ));
    else if (op=='+')
        res =opt(sum(x1 , y1,x2 ,y2  ));
    else if(op=='/')
        res =opt(prod(x1 , y1 ,y2 ,x2 ));
    else 
        res =opt(sum(x1 , y1 , -x2 ,y2));
    ll sign = ((double)res.ff / (double)res.ss)< 0 ? -1 : 1 ;
    printf("%d / %d\n" , sign* abs(res.ff) , abs(res.ss));
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