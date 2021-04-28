#include <bits/stdc++.h>
using namespace std ;
vector<int>arr ;
int memo[10010][10010] ;
int cnt =0 ;
int dp(int ind , int prev )
{
    if(ind == arr.size()) 
        return 0 ;
    int &stat=memo[ind][prev ];
    if(stat !=-1)
        return stat ; 
    int res =0; 
    int leave  =dp(ind+1 , prev );
    if(ind > prev+1 ||ind == prev  )
        res = max ( dp(ind+1 ,ind) + arr[ind] , leave  );
    else if (ind == prev+1)
        res =leave;
    cnt++;
    return stat =res ;

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
        printf("case %d: %d\n",k , dp(0,0));
    }
}


