#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    int n ; cin>>n ; 
    int arr[n];
    unsigned long long res =1 ;  
    for(int i =0 ;i < n ;i++)
        cin>>arr[i] ,res  *=arr[i];
    cout<<res<<endl;
}