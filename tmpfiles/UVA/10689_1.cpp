#include <bits/stdc++.h>
#define ll long long
using namespace std ;
int main() {
    int mod[]  = { 60 ,300 ,1500,15000};
    int t ; cin>>t;
    while(t--)
    {
        int a , b  ,n, m ;
        cin>>a>>b>>n>>m;
        int arr[mod[m-1]];
        memset(arr, 0 , mod[m-1]);
        arr[0]=a ; arr[1]=b;
        for(int i =2 ; i <= mod[m-1] ; i++)
            arr[i]=(arr[i-1]+arr[i-2])%(ll)pow(10,m);
        cout<<arr[n%mod[m-1]]<<endl;
    }
    return 0;
}
