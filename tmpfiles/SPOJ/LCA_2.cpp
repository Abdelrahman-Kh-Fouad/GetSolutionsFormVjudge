#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int N = 1001;
int parent[N];
int *PathToRoot(int node )
{   
    int cur = node ;
    int *path = new int[N];
    memset(path , -1 ,sizeof path);
    int ind = 0 ;
    while(cur !=-1)
    {
        path[ind++] =cur ;
        cur =parent[cur];
    }
    return path;
}
bool bs (int * arr , int n , int tar )
{
    int l =0 , r = n-1 ; 
    int mid ;
    while(l<r)
    {
        mid = (l+r )/2 ;
        if(arr[mid] > tar) r = mid -1 ;
        else if(arr[mid] < tar) l =mid+1 ;
        else return 1 ;   
    }
    return 0 ;
}
void solve()
{
    int n ; cin>>n ;
    memset(parent , -1 ,sizeof parent);
    for(int i =0; i  <n ;i++)
    {
        int m ; cin>>m ;
        int tt ;  
        for(int j =0 ; j < m ;j++)
            cin>>tt , parent[tt-1]=i;
    }
    int q ; cin>>q ; 
    while(q--)
    {
        int l ,r ; 
        cin>> l >> r ; 
        int *path1 = PathToRoot(l-1) ,*path2 = PathToRoot(r-1);
        
        sort(path2 , path2 +n );
        int res = -1; 
        for(int i = 0 ; i <n ; i+=1)
        {
            if(bs(path2 , n ,path1[i]))
            {
                res = path1[i];
                break;
            }
        }

        cout <<res +1<<endl;
        
    }
}   
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}