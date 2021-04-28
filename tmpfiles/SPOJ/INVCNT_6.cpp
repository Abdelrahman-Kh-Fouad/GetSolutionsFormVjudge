#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
int conc(vector<int>&arr , int left , int mid ,int right ){
    int cnt =0 ; 
    vector<int>tmp;
    int i =left ,j=mid , k =right ;
    while((i<= mid-1) && (j<= right)){
        if(arr[i] <= arr[j]) tmp.pb(arr[i++]);
        else tmp.pb(arr[j++]) ,cnt+=mid - i;
    }
    while(i<=mid -1) tmp.pb(arr[i++]);
    while(j<=right ) tmp.pb(arr[j++]);
    for( i = left , j = 0 ; i<=right ; j++,i++) arr[i]=tmp[j]; 
    return cnt ;
}
int div (vector<int>&arr ,int i ,int j ){
    if(i>=j) return 0;

    int mid = (i+j)/2 ,  cnt =0 ; 
    cnt +=div(arr , i , mid );
    cnt +=div(arr , mid+1 , j );
    cnt +=conc(arr , i , mid +1 , j);
    return cnt ;
}
void solve()
{
    int n ; cin>>n ; 
    vector<int>arr(n) ;
    for(auto &i : arr) cin>> i ;
    cout<<div(arr ,  0 , sz(arr)-1)<<endl; ;
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