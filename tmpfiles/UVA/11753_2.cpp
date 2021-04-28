#include<bits/stdc++.h>
using namespace std ; 
vector<int>arr;
int n  , k; 
map <pair<int ,int >,int> memo;
int dp(int l = 0 , int r = n-1 )
{   
    if(l >=r )return 0 ;

    if(memo.count({l ,r })) return memo[{l , r }];
    int &stat  = memo[{l,r}];

    if(arr[l] == arr[r])return stat =  dp(l +1 , r-1);
    else
        return stat = min (dp(l+1  , r ) , dp(l ,r -1  )) +1 ; 
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
        memo.clear();
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