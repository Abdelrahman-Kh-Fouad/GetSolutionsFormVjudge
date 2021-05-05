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
void solve()
{
    int n ,a ,b ; cin>> n >>a >> b ;
    vector<int>arr(n);
    unordered_map <int ,int >ch;
    for(int i =0 ;i < n ;i++)
        cin>>arr[i] ,ch[arr[i]]++;

    double res =0;
    double hit = 0 ;
    // for(int i =0 ;i  <n ;i++ )
    // {
    //     for(int j =0 ;j <n ;j++)
    //     {
    //         if(arr[i] == a && arr[j] == b)hit +=1.0 ;
    //         res+=1.0 ; 
    //     }
    // }
    hit = ch[a]* ch[b];
    res= n*n; 
    res = hit /res ;
    printf("%0.6f\n" , res);

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