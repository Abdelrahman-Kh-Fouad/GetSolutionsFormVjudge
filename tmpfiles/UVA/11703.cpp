#include <bits/stdc++.h>
using namespace std ;
int memo[(int)1e7+1];
int dp(int num )
{
    if(num<=0)
        return 1; 
    int &stat = memo[num];
    if(stat !=-1 )return stat ;
    
    return stat = dp(floor(num-sqrt((double)num))) + dp(floor(log((double)num))) +dp(floor(num * sin((double)num)*sin((double)num)));
}
int main()
{
    memset(memo , -1 , sizeof(memo));
    int n ; 
    while(cin>>n && n!=-1)
        cout<<dp(n)<<endl;
}