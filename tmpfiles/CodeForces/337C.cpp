#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000009
using namespace std ;
ll poww (ll x , ll y )
{
    ll res =1;
    x %=MOD;
    while (y>0)
    {
        if(y%2)
            res=(res*x)%MOD;
        y /=2;
        x=(x*x) %MOD;
    }
    return res;
}

int main() {
    ll n,m,k;
    cin>>n>>m>>k;
    if(ceil(n/2.00)>= m )
        cout<<m%MOD<<endl;
    else
        cout<<(poww(k ,m-ceil(n/2.00))+m) % MOD;

    return 0;
}
