#include<bits/stdc++.h>
using namespace std ;
#define p pair<int,int>
#define ff first 
#define ss second
int main ()
{
    int t ; cin>>t ;
    while(t--)
    {
        int n ; cin>>n;
    p arr[n];
    for(int i =0 ;i <n ;i++)cin>>arr[i].ff >>arr[i].ss ;
    sort(arr, arr+n);
    vector<int>lis(n,1);

    for(int i =0 ;i < n ;i++)
        for(int j =i-1 ; j>=0 ;j--)
            if(arr[i].ff > arr[j].ff && arr[i].ss > arr[j].ss)
                lis[i]=max(lis[i] , lis[j]+1);
    bool flag [n]={0};
        int res =0; 
        for(int j =0 ; j< n ;j++)
        {
            int cnt =0 ; 
            int prev =-1;

            for(int i =0 ;i <n ;i++)
            {
                if(flag [i])
                    continue;
                if(lis[i]-prev ==1 || prev ==-1 )
                {
                    prev =lis[i] ;
                    flag[i]++;
                    cnt++;
                }
            }

            if(cnt )res++;
            else 
                break;
        }
        cout<<res<<endl;
    }
    return 0 ;
}