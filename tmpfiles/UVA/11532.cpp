#include<bits/stdc++.h>
using namespace std ; 
#define setbit(num  , bit ) (num )|=(1 <<bit)
int main ()
{
    int T ; cin>>T ;
    while (T--)
    {
        int ones , zeros ; 
        cin>>ones >> zeros;
        long long  res = 0;
        bool f =1 ; 
        for (int i =0 ;ones>0;i+=3)
        {
            if(ones)
                setbit(res , i );
            ones--;
            if(ones )
                 setbit(res , i+2 );
            ones-=1;zeros--;
        }
        cout<<res <<endl;

    }
    return 0 ;
}