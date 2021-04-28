#include <bits/stdc++.h>
using namespace std ;
#define N 1000000
vector<bool>isprime(N+1 , 1);
vector<int >prime;
void sieve()
{
    isprime[0]=isprime[1]=0;
    for(int i =2 ; i *i<=N;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            for(int j =i*2 ; j <=N ;j+=i)
                isprime[j]=0;
        }
    }
}
int main() {
    int n ;cin>>n;
    sieve();
    while(n--)
    {
        int l ,r ;cin>>l>>r;
        map<int,int>freq;
        int it_l=lower_bound(prime.begin() , prime.end() ,l)-prime.begin();
        int it_r=upper_bound(prime.begin() , prime.end() ,r)-prime.begin();

        for(it_l ;it_l+1<=it_r;it_l++ )
            freq[prime[it_l+1]-prime[it_l]]++;
        int res =-1;
        int maxx=-1;
        for(auto i : freq)
        {
            if(i.second>maxx && i.second!=0)
                maxx=i.second , res=i.first;
        }
        if(maxx==-1)
            cout<<"No jumping champion"<<endl;
        else
            cout<<"The jumping champion is "<<res<<endl;
    }
    return 0;
}
