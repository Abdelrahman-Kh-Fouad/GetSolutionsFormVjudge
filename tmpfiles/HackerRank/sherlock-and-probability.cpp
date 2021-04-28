#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;

int bs(vector<int>&arr , int tar){
    int l = 0 , r =sz(arr)-1 ,mid =-1  ,res =-1;
    while(l<=r)
    {
        mid = (l+r)/2 ;
        if(arr[mid] >= tar) res = mid , r = mid-1 ; 
        else l = mid+1 ; 
    }
    return res ;
}
void solve()
{
    int n , k ;cin>>n>>k ; 
    string s ; cin>>s ;
    vector<int>sum(n+1 , 0);
    for(int  i  =1 ;  i <= n ;i++ )
        sum[i]+= (s[i-1] == '1') +sum[i-1];
    
    ll res = 0 ;
    for(int i =1 ; i <=n ;i++)
    {
        int end = min( n, i+ k); 
        int start = max ( i - k  ,1 );
        res+=(s[i-1] =='1')?  sum[end] - sum[start-1]   : 0 ;
    }
    ll tt = __gcd((ll)res , (ll)n*n);
    printf("%d/%d\n" , res /tt , ((ll)n*n) /tt);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}