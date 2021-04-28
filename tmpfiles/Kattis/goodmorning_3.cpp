#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
set<int >num ;
void go(vector<vector<int>>&arr ,  int n , int m , int number = 0)
{   
     num.insert(number);
    if(n >=0 && n <sz(arr) && m>= 0 && m<sz(arr.front()) && arr[n][m]!=-1 && floor(log10(number)) +1 < 3 )
    {
        
        if(n !=3 || m!= 1)
            go(arr , n , m , number *10 + arr[n][m]);    
        go(arr , n+1 ,m ,number );
        go(arr , n ,m+1 ,number );
        go(arr , n+1 , m ,number *10 + arr[n][m] );
        go(arr , n , m+1 ,number *10 + arr[n][m] );
    }

}
void init()
{
    vector<vector<int>>arr ={{1,2,3},
                  {4,5,6},
                  {7,8,9},
                  {-1,0,-1}};
    go(arr , 0, 0);
}
void solve()
{   
    int k ;cin>> k ;
    auto it = num.begin(); 
    while(it != num.end())
    {
        if(*it>=k )break;
        it++;    
    }
    if(*it == k )
        cout<<k<<endl;
    else
    {
        int nx =*it ; 
        int pr = *std::prev(it ,1 );
        if(nx - k < k -pr) cout<<nx <<endl;
        else cout<<pr<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}