#include<bits/stdc++.h>
using namespace std ; 
string a ,b ;
int memo[50][50];
int dp (int i=0 , int j =0)
{
    if(i==a.length() || j ==b.length())
        return 0 ;
    int &stat=memo[i][j]; 
    if(a[i]==b[j])
        return dp(i+1 , j+1 ) ;
    return stat =  min(dp(i+1 ,j ) , dp(i ,j +1 ))+1 ;

}
stringstream ress ;
string tt (int t )
{
    if(t  /10==0)
        return "0"+to_string(t) ;
    else
        return to_string(t); 
}
void trace (int i =0, int j =0 )
{
    if(i== a.length())
    {
        while(j++ ==b.length())ress<<"I" << b[j]<<tt(j+1);
        return ;
    }   
    if(j==b.length())
    {
        while(i++ ==a.length())ress<<"D" << a[i]<<tt(i+1);
        return ;
    }
    if(a[i]==b[j])
        trace(i+1 , j+1 );
    else
    {
        int ch = dp(i , j );
        if(ch == dp(i+1 , j+1)+1)
            ress<<"C"<<b[j]<< tt(j+1 ), trace(i+1 ,j+1 );
        else if (dp(i ,j+1) +1 == ch)
            ress<<"I"<<b[j]<< tt(j+1 ),trace(i ,j+1 );
        else
            ress<<"D"<<a[i]<< tt(j+1),trace(i+1 ,j);

    }
}

int main ()
{
    while(cin>>a>>b && a !="#")
    {
        memset(memo , -1 , sizeof memo);
        cout<<dp()<<endl;   
        trace();
        ress<<"E\n";
        cout<<ress.str();
        
    }
}