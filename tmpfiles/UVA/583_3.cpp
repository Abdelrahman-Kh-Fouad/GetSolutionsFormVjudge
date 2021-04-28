#include<bits/stdc++.h>
using namespace std ;
vector<int>primes ; 
vector<int>is_prime; 
void sieve ()
{
    is_prime.assign(46342 , 1 );is_prime[0]=is_prime[1] = 0 ;
    
    for(int i =2;i*i  <=46341 ; i++)
    {
        if(is_prime[i])
        {
            for(int j = i *2 ; j<=46341 ; j+= i )
                is_prime[j]=0;
            primes.push_back(i);
        }
    }
}
int main()
{   
    sieve();
    int n ;  
    while(cin>>n , n)
    {
        printf("%d = " , n );
        vector<int >res ; 
        if(n < 0 ) cout<<"-1 x ";
        n = abs (n );
        for(int i = 0  ; i<primes.size() && n!=1 ;i++)
        {
            while(n % primes[i] ==0 )
                res.push_back(primes[i]) , n /= primes[i];
            
        }
        if(n > 1 )
            res.push_back(n);
        for (int i =0 ;i  <res.size() ;i++)
        {
            if(i != 0 )cout<<" ";
            cout<<res[i];
            if(i != res.size()- 1 )cout<<" x";
        }
        
        cout<<endl;

    }


    
}