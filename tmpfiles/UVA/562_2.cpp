#include<bits/stdc++.h>
using namespace std ;
int memo [150 ][50050]; 
int dp (vector<int> & arr ,int a =0  ,int b =0   , int ind =0  )
{
    if(ind == arr.size())
        return abs(a-b);
    return min (dp(arr , a + arr[ind] , b , ind+1 ) ,dp(arr , a , b+arr[ind] , ind+1 ));
}
int main ()
{
    int t ; cin>>t ; 
    while(t--)
    {
        memset(memo , -1 , sizeof memo);
        int n ; cin>>n ; 
        vector<int>arr(n);
        for(int i =0 ;i < n ;i++)cin>>arr[i];
        cout<<dp(arr )<<endl;
    }
}