#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;

int merge (vector<int>&arr , int left , int mid ,int right ){
    int i = left ,j = mid+1 ;
    int lim1 = mid ,lim2 = right ;
    int cnt =0 ;
    vector<int>tmp ; 
    while(i <=lim1 && j<=lim2) 
        if(arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else 
            tmp.pb(arr[j++]) , cnt +=mid  - i+1 ; 
    while(i<=lim1 ) tmp.pb(arr[i++]);
    while(j<=lim2 ) tmp.pb(arr[j++]);
    for(i = left ; i <= lim2 ;i++)
        arr[i] = tmp[i-left];
     return cnt ;
}
int mergesort (vector<int>&arr ,int i ,int j ){
    if(i>=j) return 0;
    int mid = (i+j)/2 ,  cnt =0 ; 
    cnt +=mergesort(arr , i , mid );
    cnt +=mergesort(arr , mid+1 , j );  
    cnt +=merge(arr , i , mid  , j);
    return cnt ;
}
void solve()
{
    int n ; cin>>n ; 
    vector<int>arr(n) ;
    for(auto &i : arr) cin>> i ;
    cout<<mergesort(arr ,  0 , sz(arr)-1)<<endl; ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in" ,"r" ,stdin);
    int t ; cin>>t ;
    while(t--)solve();
    return 0 ; 
}