#include<bits/stdc++.h>
using namespace std ;
vector<long long >primes ; 
vector<int>is_prime; 
void sieve ()
{
    is_prime.assign(46349 , 1 );is_prime[0]=0 ;
    
    for(long long i =2;i<=46345 ; i++)
    {
        if(is_prime[i])
        {
            for(long long  j = i *2 ; j * j <=46345 ; j+= i )
                is_prime[j]=0;
            primes.push_back(i);
        }
    }
}
unsigned long long p(int x )
{
    if(x ==0 )return 1 ;
    unsigned long long res = 1 ; 
    if(x %2 ==1 )
        res *= 2 ; 
    unsigned long long tmp  =p(x /2 );
    return tmp *tmp * res  ; 
}
int main()
{   
    sieve();
    set<unsigned long long >num;
    for(int i =1 ; i <=31 ; i++)
        num.insert(p(i-1) * (p(i) -1));
    long long  n ;  
    while(cin>>n , n)
    {
        if(!num.count(n))
            printf("Perfect: %lld!\n" , p(n -1 ) * (p(n) -1 ));
        else 
        {
            if(is_prime[n])
                cout<<"Given number is prime. But, NO perfect number is available.\n";
            else 
                cout<<"Given number is NOT prime! NO perfect number is available.\n";
        }

    }


    
}