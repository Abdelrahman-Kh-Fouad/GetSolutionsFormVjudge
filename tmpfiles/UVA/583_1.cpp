#include<bits/stdc++.h>
using namespace std ;
vector<int>primes ; 
vector<int>is_prime; 
void sieve ()
{
    is_prime.assign(10000 , 1 );is_prime[0]=is_prime[1] = 0 ;
    
    for(int i =2;i*i  <=10000 ; i++)
    {
        if(is_prime[i])
        {
            for(int j = i *2 ; j<=10000 ; j+= i )
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
        printf("%d =" , n );
        vector<int >res ; 
        res .push_back((n <0)  ? -1 : 1 );
        n = abs (n );
        int end = lower_bound(primes.begin() ,primes.end() , n) - primes.begin();
        if(end == primes.size())end -- ;

        for(int i = 0 ; i <=end ;i++)
        {
            while(n % primes[i] ==0 )
                res.push_back(primes[i]) , n /= primes[i];
        }
        for (int i =0 ;i  <res.size() ;i++)
        {
            cout<<" "<<res[i];
            if(i != res.size()- 1 )cout<<" x";
        }
        cout<<endl;

    }
    
}