#include<bits/stdc++.h>
using namespace std ; 

bool cmp(pair<long long ,int > x , pair<long long ,int > y)
{
    if( x.first == y.first)return x.second < y.second;
    return x.first > y.first;
}
int main ()
{

    int n ; cin>>n ;
    int k ; cin>>k ;
    int arr[n]; for(int i =0 ; i  <n ;i++)cin>>arr[i];
    int sum[n+1]={0};for(int i =0 ; i  <n ;i++)sum[i+1]=arr[i]+sum[i];
    vector<pair<long long  ,int >>res ; 
    for(int i = 0 ;i  <=n-k ;i++)
        res.push_back({sum[i+k] - sum[i] , i } );
    int c , b ; 
    long long  maxx =-1; int prev =-1;
    long long cur =0 ;
    for(int i=k,j=0;i<res.size();j++,i++)
    {
        if(res[j].first>maxx)
            maxx = res[j].first,prev=j;
        
        if(cur<maxx+res[i].first)
            cur=maxx+res[i].first,b=i ,c=prev;
    }
    cout<< c+1 <<" "<<b+1 <<endl;
}