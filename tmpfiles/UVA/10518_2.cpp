#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull n , m ; 
    int tt =0 ; 
    while(scanf("%lld %lld" ,&n ,&m )&& (n!=0 || m!=0) )
    {
        vector<ll>sum(2);
        sum[0]=sum[1] =1 ;
        ll lim = 10001;  
        for(int i = 2 ; i <= (int)10001 ;i++ )
        {
            sum.pb((sum [i-2] + sum[i-1] +1 )%m);
            if(sum[i] ==1 &&sum[i-1]  ==1 )
            {
                lim = i ;
                break;
            }
        }
        lim -- ;
        printf( "Case %d: %lld %d %d\n" ,++tt , n , m ,sum[n % lim ]);
    }
    return 0 ; 
}