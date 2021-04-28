#include <bits/stdc++.h>
using namespace std ;
bool valid (vector<int>&arr , int k )
{
    for (int i =1 ; i < arr.size() ;i++)
    {
        if (arr[i] - arr[i-1] < k )
            continue;
        if (arr[i]-arr[i-1] > k )
            return 0;
        if (arr[i]-arr[i-1]== k )
            k--;
    }
    return 1;
}
int min (vector<int>&arr)
{
    int l =0 , r =1000000;
    int mid  ,res =-1;
    while (l<r)
    {
        mid = l +(r-l)/2;
        if (valid(arr , mid ))
            r =mid;
        else
            l = mid+1;
    }
    return l;
}
int main() {
    int t ; cin>>t ;
    for(int k =0 ; k < t ;k++)
    {
        int n ; cin>>n;
        vector<int>arr(n);
        for(int i =0 ;i < n ;i++)cin>>arr[i];
        printf("Case %d: %d\n", k+1,min(arr) );
    }
    return 0;
}
