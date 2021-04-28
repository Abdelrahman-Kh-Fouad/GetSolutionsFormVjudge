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
pair<int,int> sum (int x1 ,int y1 ,int x2 ,int y2  )
{
    return {y1 * x2 + x1 * y2  , y1 * y2 };
}
pair<int,int>prod(int x1 ,int y1 ,int x2 ,int y2)
{
    return {x1 *x2 , y1 *y2 };
}
pair<int,int> opt(pair<int,int>x )
{
    int tmp = __gcd(abs(x.ff) , abs(x.ss) );
    x.ff /=tmp , x.ss/=tmp;
    return x ; 
}
void solve()
{   
    int x1 ,y1 , x2 ,y2 ; 
    char op ;
    cin>>x1 >> y1 >> op >> x2 >> y2 ;
    pair<int,int>res ; 
    if(op =='*')
        res = opt(prod(x1 ,y1 ,x2 ,y2 ));
    else if (op=='+')
        res =opt(sum(x1 , y1,x2 ,y2  ));
    else if(op=='/')
        res =opt(prod(x1 , y1 ,y2 ,x2 ));
    else 
        res =opt(sum(x1 , y1 , -x2 ,y2));
    int sign = (res.ff / (double)res.ss)< 0 ? -1 : 1 ;
    printf("%d / %d\n" , sign* abs(res.ff) , abs(res.ss));
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