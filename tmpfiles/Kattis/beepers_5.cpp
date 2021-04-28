#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cout<<(#x)<<": \""<<x<<"\""<<endl
#define debugVec(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
 
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.ff << ", " << p.ss << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    for(int i =0; i< sz(v) ; i++) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}
typedef long long ll;
typedef unsigned long long ull;
// int memo[21][21];
// bool used[21][21];
// int xx[]={-1 ,1 , 0, 0};
// int yy[]={0 ,0 , -1, 1};
// int q ; 
// pair<int,int>start ;

// inline bool valid (vector<vector<int>>&arr , pair<int,int> node)
// {
//     return (node.ff >= 0 && node.ff < sz(arr) && node.ss >= 0 && node.ss < sz(arr.front()));
// }
// void dp(vector<vector<int>>&points , pair<int,int> node, int ind = 0 )
// {

// }

int dist(pair<int,int>&x ,pair<int,int>&y )
{
    return abs(x.ff -y.ff) + abs(x.ss-y.ss);
}
void solve()
{
    int n ,m ; cin>>n >>m ;
    pair<int,int>start;
    cin>>start.ff >> start.ss ;
    --start.ff , --start.ss;
    int q ; cin>>q ; 
    vector<pair<int,int>>points(q);
    for(int i =0 ;i < q ;i++)
    {
        int x ,y ; cin>>x >>y  ;
        points[i] = (make_pair(--x,--y));
    }
    int res =0 ;
    pair<int,int> cur=start  ;
    set<pair<int,int>>used ;
    while(used.size()-1!=points.size())
    {
        int minn =INT_MAX;
        pair<int,int>next ;
        for(int i =0 ;i < q ;i++)
        {
            if(!used.count(points[i])&& minn > dist(cur , points[i]))
                minn =dist(cur , points[i]) ,next = points[i]; 
        }
        res += minn; 
        used.insert(cur);
        cur =next;
    }   
    res += dist(cur ,start);
    cout<<res<<endl;
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