#include<bits/stdc++.h>
using namespace std ; 
#define getbit(n , bit) (1<<(bit))&(n) 
int gcd (int a ,int  b )
{
    if(b ==0  )return a ; 
    return gcd(b , a%b);
}
int lcm(int a , int b )
{
    return a *b / gcd(a , b )  ;
}
int main ()
{
    int n , m ; 
    while(cin>>n>>m)
    {
        int arr[m];
        int res =0; 
        for(int i =0 ;i < m;i++)cin>>arr[i];
        for(int i = 1 ;i <  1<< m ;i++)
        {
            int ll = 1 ;
            int count =0;  
            for(int bit =0 ; bit < m ;bit++)
            {
                if(getbit(i , bit))
                    ll =lcm(ll , arr[bit]),count++;
            }
            
            if( count % 2==0 )
                res -= n/ll; 
            else  
                res += n/ll;
            
            
        }
        cout<<n - res<<endl;
    }
    return 0;  
}
