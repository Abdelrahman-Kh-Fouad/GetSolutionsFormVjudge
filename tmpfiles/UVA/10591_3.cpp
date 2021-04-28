#include <bits/stdc++.h>
#define ll long long
using namespace std ;
ll go(ll num)
{
    ll sum=0;
    while (num)
    {
        int tmp=(num%10);
        sum+=tmp*tmp;
        num/=10;
    }
    return sum;
}
int main() {
    int t ; cin>>t;
    for (int k =1 ; k<=t ;k++)
    {
        long long n ; cin>>n;
        int stop  =n ;
        bool f =0;
        while(!(n==1 || (stop==n && f )))
        {
            n=go(n);
            f=1;
        }
        if(n==1 )
            cout<<"Case #"<<k<<": "<<stop<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<k<<": "<<stop<<" is a UnHappy number."<<endl;


    }
    return 0;
}
