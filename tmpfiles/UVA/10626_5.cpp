#include<bits/stdc++.h>
using namespace std ;
int n ,n1 ,n5,n10;
map<vector<int>,int>memo;
struct state {
    int n1 , n5 ,n10 ;
    state (int n1 , int n5 , int n10)
    {
        this->n1 = n1 ; this->n5 = n5 ;this->n10 = n10;
    }
};
int oo=1e9;
int dp(int res  , state cur )
{
    if(res > n)
        return oo ;
    if(res == n)
        return 0 ;
    if(memo.count({res , cur.n1 ,cur.n5 ,cur.n10}))
        return memo[{res , cur.n1 ,cur.n5 ,cur.n10}];
    int ch1= oo,ch2=oo , ch3=oo, ch4 =oo,ch5=oo  ;
    if(cur.n10>0)
        ch1=dp(res+1 , state(cur.n1+2 , cur.n5 ,cur.n10 -1 ))+1;
    if(cur.n5>=2)
        ch2=dp(res+1 , state(cur.n1 +2, cur.n5-2 ,cur.n10  ))+2 ;
    if(cur.n5>0 && cur.n1>=3)
        ch3=dp(res+1  , state(cur.n1-3 , cur.n5-1 ,cur.n10  ))+4;
    if(cur.n10 >0&& cur.n1>=3)
        ch4=dp(res+1 , state(cur.n1-3 , cur.n5+1,cur.n10 -1 ))+4;
    if(cur.n1>=8)
        ch5=dp(res+1 , state(cur.n1-8 , cur.n5 ,cur.n10 ))+8 ;


    int product = min(min(min(ch1 , ch2 ) ,min (ch3 ,ch4)), ch5 );  
    memo [{res , cur.n1 ,cur.n5 ,cur.n10}] =product;
    return product ;
}
int main ()
{
    int t ; cin>>t ;
    while(t--)
    {
        cin>>n>>n1>>n5>>n10;
        memo.clear();
        cout<<dp(0 , state(n1,n5,n10))<<endl;
    }
}