#include <bits/stdc++.h>
using namespace std ;
bool valid (vector<int>&arr , int k )
{
    for (auto i : arr )
    {
        if (i > k )
            return 0;
        if (i== k )
            k--;
    }
    return 1;
}
int min (vector<int>&arr)
{
    int l =1 , r =100000;
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
        vector<int>res;
        for(int i =1 ;i < n ;i++)
            res.push_back(arr[i]-arr[i-1]);
        printf("Case %d: %d\n", k+1,min(res) );
    }
    return 0;
}
