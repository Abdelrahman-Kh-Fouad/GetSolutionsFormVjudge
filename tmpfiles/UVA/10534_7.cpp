#include<bits/stdc++.h>
using namespace std ;
int n ; 
int arr[100000];

int lis()
{
    vector<int>l(n,INT_MAX); 
    int cnt1 =0; 
    for(int i =0 ;i < n ;i++)
    {
        int ind =lower_bound(l.begin() , l.end() , arr[i] ) -l.begin();
        l[ind]=arr[i];
        cnt1= max(cnt1 , ind );
    }
    return cnt1+1;    
}
int main()
{
    while(cin>>n)
    {
        for(int i =0 ;i <n ;i++)cin>>arr[i];
        int o1 = lis();
        reverse(arr , arr+n);
        int o2 = lis();
        cout<<2*(min(o1,o2)-1)+1<<endl; 

        
    }
    return 0 ;
}