#include <bits/stdc++.h>
using namespace std ;
#define N 1000000
vector<bool>isprime(N+1 , 1);
vector<int >prime;
static int binary( int t ,bool lower)
{
    int ans = -1, start = 0, end = prime.size()-1;
    while(start <= end)
    {
        int mid = (start + end )/2;
        if(lower)
        {
            if(prime[mid] >= t)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        else
        {
            if(prime[mid] <= t)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }
    return ans;

}
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
        int it_l=binary(l , 1) ;
        int it_r= binary(r , 0);
        if(it_l ==-1 || it_r ==-1 )
        {
            cout<<"No jumping champion"<<endl;
            continue;
        }
        for(it_l ;it_l+1<=it_r;it_l++ )
           freq[prime[it_l+1]-prime[it_l]]++;
        int res =-1;
        int maxx=-1;
        for(auto i : freq)
        {
            if(i.second>maxx )
                maxx=i.second , res=i.first;
        }
        bool f =0;
        for (auto i : freq )
            if(maxx==i.second && res !=i.first)
                f=1;
        if(!freq.size() || f)
            cout<<"No jumping champion"<<endl;
        else
            cout<<"The jumping champion is "<<res<<endl;
    }
    return 0;
}
