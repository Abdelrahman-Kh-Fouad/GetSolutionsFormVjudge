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
ll MOD = (1<< 31) -1;
inline bool valid (vector<vector<char>>&arr , int x ,int y ){
    return (x < sz(arr) && y < sz(arr.front()) && arr[x][y] != '#');
}

ll memo [1001][1001];
ll dp(vector<vector<char>>&arr , int x =0  , int y = 0 )
{
    if(x ==sz(arr)-1  &&y == sz(arr.front())-1 )
        return 1 ;
    ll &stat = memo[x][y];
    if(stat !=-1) return stat ;
    ll ch1 = valid(arr , x+1 , y )? dp(arr ,x+1 , y ): 0;
    ll ch2 = valid(arr , x , y+1 )? dp(arr ,x , y+1 ): 0;

    return stat = (ch1 %MOD +ch2 %MOD )%MOD;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ;cin>>n ; 
    vector<vector<char>>arr(n,vector<char>(n));
    for(int i =0 ; i <n ;i++)
        for(int j =0 ;j < n ;j++)
            cin>>arr[i][j];
    memset(memo , -1 ,sizeof memo);
    ll res = dp(arr);
    if(res )cout<<res <<endl;
    else cout<<"THE GAME IS A LIE"<<endl;

    return 0 ; 
}