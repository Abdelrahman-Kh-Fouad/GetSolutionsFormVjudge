#include<bits/stdc++.h>
using namespace std ;
int n ; 
int arr[100000];

int lis(vector<int>&res)
{
    vector<int>l(n,INT_MAX); 
    int cnt1 =0; 
    for(int i =0 ;i < n ;i++)
    {
        int ind =lower_bound(l.begin() , l.begin()+cnt1 , arr[i] ) -l.begin();
        l[ind]=arr[i];
        if(cnt1==ind)
            cnt1++; 
        res[i] =cnt1;
    }
    return cnt1+1;    
}
int main()
{
    while(cin>>n)
    {
        for(int i =0 ;i <n ;i++)cin>>arr[i];
        vector<int>pos(n) , neg(n);
        int o1 = lis(pos);
        reverse(arr , arr+n);
        int o2 = lis(neg);
        int res =0;
        for(int i =0 ;i<n ;i++)
            res=max(res , 2*(min(pos[i] , neg[i])-1)+1 );
        cout<<res<<endl;
        
    }
    return 0 ;
}