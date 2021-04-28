#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int dist(pair<int,int>&x ,pair<int,int>&y )
{
    return abs(x.ff -y.ff) + abs(x.ss-y.ss);
}
set<pair<int,int>>used;
pair<int,int>start;
int res =INT_MAX ; 
void go(vector<pair<int,int>>&points , pair<int,int>node ,int sum = 0  )
{
    if(used.size() == points.size())
    {
        res =min(res ,dist(node , start)+sum);
        return ;
    }
    for(int i =0 ;i < sz(points) ;i++)
    {
        if(!used.count(points[i]))
        {
            used.insert(points[i]) ;
            go(points , points[i] , sum +dist(points[i] ,node) )  ;
            used.erase(points[i]) ;
        }
    }
    
}
void solve()
{
    int n ,m ; cin>>n >>m ;
    cin>>start.ff >> start.ss ;
    --start.ff , --start.ss;
    int q ; cin>>q ; 
    vector<pair<int,int>>points(q);
    for(int i =0 ;i < q ;i++)
    {
        int x ,y ; cin>>x >>y  ;
        points[i] = (make_pair(--x,--y));
    }
    go(points , start );
    cout<<res <<endl;
    res =INT_MAX;
    
    // int res =0 ;
    // pair<int,int> cur=start  ;
    // set<pair<int,int>>used ;
    // while(used.size()-1!=points.size())
    // {
    //     int minn =INT_MAX;
    //     pair<int,int>next ;
    //     for(int i =0 ;i < q ;i++)
    //     {
    //         if(!used.count(points[i])&& minn > dist(cur , points[i]))
    //             minn =dist(cur , points[i]) ,next = points[i]; 
    //     }
    //     res += minn; 
    //     used.insert(cur);
    //     cur =next;
    // }   
    // res += dist(cur ,start);
    // cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in" ,"r" ,stdin);
    // freopen("out" ,"w" ,stdout);


    int t ; cin>>t ;
    while(t--)
    {
        solve();
    }
    return 0 ; 
}