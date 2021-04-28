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
        set<ll>ch;
        while(!(n==1 || ch.count(n)))
            ch.insert(n),n=go(n);

        if(n==1 )
            cout<<"Case #"<<k<<": "<<stop<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<k<<": "<<stop<<" is a UnHappy number."<<endl;


    }
    return 0;
}
