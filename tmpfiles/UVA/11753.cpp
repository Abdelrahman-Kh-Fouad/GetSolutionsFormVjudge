#include<bits/stdc++.h>
using namespace std ; 
vector<int>arr;
int n  , k; 
int memo [100050][21][21];
int dp(int l , int kl , int kr )
{   
    int r = n- l -1 +kl - kr ;
    if(l >=r )return 0 ;

    int &stat  = memo[l][kl][kr];
    if(stat !=-1)
        return stat ; 
    if(kl + kr >=  k ) return stat =1e9 ;
    if(arr[l] == arr[r])return dp(l +1 , kl , kr);
    else
    return min (dp(l , kl+1 , kr ) , dp( l+1 , kl , kr+1 )) +1 ; 
}
int main ()
{
    int t ; cin>>t ; 
    int c = 1 ; 
    while(t -- )
    {
        cin>>n >>k ; 
        arr.assign(n , 0);
        for(int i =0 ; i <n ;i++)cin>>arr[i];
        int l = 0 , r = n -1 ; 
        int cnt =0 ; 
        while(l <r )
        {
            if(arr[l]==arr[r])
                l++ ,r--; 
            else 
                l++ ,cnt++; 
        }
        int res = cnt ; 
        // memset( memo , -1 , sizeof memo ); 
        // int res = dp(0 , 0 , 0 );
        printf("Case %d: " , c++);
        if(res >  k  )
            cout<<"Too difficult\n ";
        else if(res == 0)
            cout<<"Too easy\n";
        else if(res > 0 )   
            cout<<res<<"\n";
    }
} 