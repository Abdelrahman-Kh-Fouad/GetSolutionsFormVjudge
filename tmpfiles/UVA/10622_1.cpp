#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<ll>primes ; 
vector<bool>is_prime(1<<16+1 , 1 );
void sieve()
{
    primes.push_back(2);
    for(ll i =3 ; i<=1<<16 ; i+=2)
    {
        if(is_prime[i])
        {
            for(ll j = 2 * i ; j* j <=1<<16 ;j+=i )
                is_prime[j]=0;
            primes.push_back(i);
        }   
    }
}
int main ()
{
    sieve();
    ll n ; 
    while (cin>>n && n )
    {
        if(n ==1 )
        {
            cout<<"1\n";
            continue;
        }
        map<ll , int >res ; 
        for(ll i  = 0 ;i < primes.size() && primes[i]*primes[i]<=n ;i++)
        {
            while (n % primes[i] == 0)
            {
                res[primes[i]]++;
                n /=primes[i];
            }
        }
        if(n!=1)res[n]++;
        cout<<res.begin()->second<<endl;
    }
    return 0 ; 

} 