#include <bits/stdc++.h>
using namespace std ;
vector<int>arr ;
int memo[10010];
// int memo[10010][10010] ;
// int dp(int ind , int prev )
// {
//     if(ind == arr.size()) 
//         return 0 ;
//     int &stat=memo[ind][prev ];
//     if(stat !=-1)
//         return stat ; 
//     int res =0; 
//     int leave  =dp(ind+1 , prev );
//     if(ind > prev+1 ||ind == prev  )
//         res = max ( dp(ind+1 ,ind) + arr[ind] , leave  );
//     else if (ind == prev+1)
//         res =leave;
//     cnt++;
//     return stat =res ;

// }


int dp(int ind )
{
    if (ind ==arr.size() )
        return 0; 

    int &stat=memo[ind];
    if(stat !=-1)
        return stat ;
    int res =0 ;
    if(ind ==0) res  = arr[0]; 
    return stat = max((ind+2 <arr.size() )? dp (ind +2  )+arr[ind+2] : dp(ind+1) , dp(ind+1))+res ;
    
}
int main ()
{
    int t ; cin>>t ;
    for (int k = 1 ;k<=t ;k++)
    {
        int n ;cin>>n ; 
        arr.assign(n, 0);
        for(int i =0 ;i < n ;i++)cin>>arr[i];
        memset(memo , -1 , sizeof memo );
        printf("case %d: %d\n",k , dp(0));
    }
}


