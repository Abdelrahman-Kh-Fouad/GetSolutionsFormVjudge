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
bool cmp(pair<int,int>&x , pair<int,int>&y){return x.ff > y.ff ;}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ; cin>>n ;
    int s ; cin>>   s ; 
    map<char , map<int ,int ,greater<int>>>mp;
    char b ; int tmp  ,f ,t = 0  ;
    for(int i =0 ;i  <n ;i++)
        cin>> b >>t >>f ,tmp,mp[b][t]+=f;

    
    vector<pair<int,int>>x, y ; 
   	for (auto it : mp['S'])
		x.push_back(it);
	for (auto it : mp['B'])
		y.push_back(it);
	sort(x.begin(), x.end(), greater<pair<int, int>>());
	sort(y.begin(), y.end(), greater<pair<int, int>>());
	for (int i = max(0, (int) x.size() - s); i < x.size(); i++)
		cout << "S " << x[i].first << " " << x[i].second << "\n";
	for (int i = 0; i < min((int) y.size(), s); i++)
		cout << "B " << y[i].first << " " << y[i].second << "\n";
    
    return 0 ; 
}