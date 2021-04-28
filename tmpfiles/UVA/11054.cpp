#include <bits/stdc++.h>
using namespace std; 
int main ()
{
    int n ;
    while(cin>> n , n!=0)
    {
        vector<int>arr(n);
        for (int i =0 ;i < n ;i++)
            cin>>arr[i];
        int sum =0;
        int cur =0;
        for (int i =0 ;i < n ;i++)
        {   
            cur+=arr[i];
            if(i!=n-1)
                sum+=abs(cur);
             
        }
        cout<<sum<<endl;
    }
}