#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
void solve()
{
    int n  ;cin>>n ; 
    int arr[n] , sorted[n];
    for(int i =0; i < n ;i++)
        cin>>arr[i] , sorted[i] =arr[i];
    sort(sorted , sorted+ n );
    ll eq = sorted[n-1 ]+sorted[n-2];
    ll cnt = 0 ;
    for(int i =0 ;i  <n-1 ;i++)
        for(int j =i+1 ;j < n ;j++)
            cnt +=(int)(arr[i] + arr[j] == eq );
    double res = (double)cnt /((n*(n-1))/2);
    printf("%0.6f\n",res);   

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--) solve();
    return 0 ; 
}