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
int n ; 
void solve()
{
    vector<int>arr(n);
    for(int i =0 ;i < n ;i++)
        cin>>arr[i];
    vector<int>lis(n,1);
    vector<int>res ; 
    for(int i =1 ; i < n ; i++)
    {
        for(int j =i-1 ; j >=0 ; j--)
        {
            if(arr[i] > arr[j] && lis[j]+1 > lis[i])
                lis[i] = lis[j]+1 ;
        }
    }
    int cnt =*max_element(all(lis)) ;
    cout<<cnt<<" "; 
    for(int i =n-1 ;i >=0 ;i--)
        if(lis[i]==cnt )
            res.pb(arr[i]) ,cnt --;
    reverse(all(res));
    for(auto &i :res)cout<<i <<" ";
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in" , "r" ,stdin);
    while(cin>>n &&n!=0 )
        solve();    
    return 0 ; 
}   