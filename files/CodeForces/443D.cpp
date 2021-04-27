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

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<double>p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    double ans = 0;
    sort(all(p));
    for(int i = 0; i < n; i++)
    {
        double re = 1 , sum = 0;
        for(int j = i; j < n; j++)
        {
            if(p[j] == 1)
            {
                ans = 1;
                break;
            }
            sum += p[j] / (1 - p[j]);
            re *= (1 - p[j]);
            ans = max(ans, sum * re);
        }
    }
    printf("%0.12f\n",ans);
   
    return 0 ; 
}