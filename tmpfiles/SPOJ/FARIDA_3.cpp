#include <bits/stdc++.h>
using namespace std ;
vector<int>arr ;
int memo[10010][3];
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


// int dp(int ind )
// {
//     if (ind >=arr.size() )
//         return 0; 
//     int &stat=memo[ind];
//     if(stat !=-1)
//         return stat;
//     return stat = max(dp (ind +2  )+arr[ind] , dp(ind+1));
    
// }
int dp(int ind , int flag )
{
    if(ind >= arr.size())return 0 ;
    int &stat = memo[ind][flag];
    if(stat !=-1)
        return stat ;
    int res =0;
    // if(flag ==2 )
    //     res = max(dp(ind , 0 ) ,dp(ind ,1 ));
    if(flag ==1)
        res = max ( dp(ind+1 , 0 ) , dp(ind +2, 1  ))+arr[ind];
    else 
        res =dp(ind+1 , 1 );
    return stat = res ;
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
        printf("case %d: %d\n",k , dp(0,1));
    }
}


