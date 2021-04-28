#include<bits/stdc++.h>
bool check(int num )
{
    bool res = 1 ; 
    int ones = 0 ;
    while(num)
    {
        if(num %10 ==1 || num %10 ==0 )ones+=(num %10 ==1)? 1: 0 ,num /=10;
        else 
        {
            res= 0; 
            break;
        }
    }
    return res && ones<=1;
}
using namespace std ;
int main ()
{
    int n ; cin>>n ; 
    int arr[n];
    vector<int>pp;
    int zeros= 0  ; 

    for(int i =0 ;i < n ;i++)
    {   cin>>arr[i];
        if(arr[i] ==0 )
        {
            cout<<0<<endl;
            return 0 ;
        }
        if(check(arr[i]))
            zeros+=floor(log10(arr[i]));
        else 
            pp.push_back(arr[i]);
    }
    
    for(int i : pp )cout<<i;
    for(int i =0 ;i < zeros ;i++)
        cout<<0;
    cout<<endl;
}       