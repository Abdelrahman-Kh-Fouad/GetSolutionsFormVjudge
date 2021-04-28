#include<bits/stdc++.h>
using namespace std ;
string a ,b ;
int memo[81][81];
int dp(int i =0 , int j =0)
{
    if(i>a.length() || j>b.length())
        return INT_MAX;
    if(i==a.length() && j==b.length())
        return 0 ;
    
    int &stat =memo[i][j];
    if(stat !=-1)return stat ; 
    if(i==a.length())
        return stat = dp(i ,j+1 )+1;
    if(j==b.length())
        return stat =dp(i+1 ,j)+1;
    if(a[i] == b[j])
        return dp(i+1 , j+1 );
    return stat = min(dp(i+1 , j) , min (dp(i ,j+1) , dp(i+1 , j+1 )) )+1;
}
stringstream res ;
int sheft;
int cnt=1 ;
void trace (int i = 0 , int j = 0 )
{
    
    if(i==a.length())
    {
        while(j !=b.length())
            res << cnt++<<" Insert "<<i+sheft+1<<","<<b[j]<<endl ,sheft++,j++;
        return;
    }
    if(j==b.length())
    {
        while(i!=a.length())
            res<<cnt++<<" Delete "<<i+sheft+1<<endl ,sheft--,i++;
        return ; 
    }
    if(a[i]==b[j])
    {
        trace (i+1 ,j+1 );
        return;
    }
    else
    {
        int insert = dp(i ,j+1 );
        int del = dp(i+1 ,j );
        int change = dp(i+1 ,j+1 );
        int opt = dp(i , j);
        //int minn = min (min(insert , del ) ,change);

        if(opt ==insert+1)
        {
            res<<cnt++<<" Insert "<<i+sheft<<","<<b[j] <<endl,sheft++;
            trace(i ,j+1);
        }
        else if(opt == del+1 )
        {
            res<<cnt++<<" Delete "<<i+sheft+1<<endl ,sheft--;
            trace(i+1 ,j);
        }
        else if(change+1==opt)
        {
            res<<cnt++<<" Replace " <<  i+sheft+1<<","<<b[j]<<"\n";
            trace(i+1 ,j+1 );
        }
    }
    
}
int main ()
{
    while(getline(cin ,a ) && getline(cin,b))
    {
        memset(memo , -1 , sizeof memo);
        cout<<dp()<<endl;
        trace();
        cout<<res.str()<<endl;
        res.str("");cnt =1 ; sheft=0;
    }
}