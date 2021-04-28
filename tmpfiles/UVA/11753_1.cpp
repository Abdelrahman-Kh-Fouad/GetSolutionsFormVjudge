#include<bits/stdc++.h>
using namespace std ; 
vector<int>arr;
int n  , k; 
int memo[100005][30][30];
int dp(int l = 0 ,int k1 = 0,int k2 =0 )
{   
    int r = n-1 - l -k2 +k1 ;
    if(l >=r )return 0 ;

    int &stat  = memo[l][k1][k2];
    if( stat !=-1)  
        return stat ; 
    
    if(arr[l] == arr[r])
        return stat = dp(l +1 ,k1, k2);
    else
        return stat = min (dp(l+1  ,k1+1  , k2 ) , dp(l  ,k1,k2+ 1 )) +1 ; 
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
        memset(memo , -1 , sizeof memo );
        int res = dp();
        printf("Case %d: " , c++);
        if(res >  k  )
            cout<<"Too difficult\n";
        else if(res == 0)
            cout<<"Too easy\n";
        else if(res > 0 )   
            cout<<res<<"\n";
    }
} 