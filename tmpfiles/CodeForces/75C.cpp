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
vector<int>dev;
void init(int x){
	dev.push_back(1);
	if(x == 1) return;
	dev.push_back(x);
 
	for(int i = 2;i<= x/i;i++){
		if(x % i == 0){
			dev.push_back(i);
			if(x/i != i) dev.push_back(x/i);
		}
	}
	sort(all(dev));
}
 
int main()
{
	
	int a,b;
	cin >> a >> b;
	int g = __gcd(a,b);
	init(g);
 
	int q;
	cin >> q;
 
	while(q--){
		int l,r;
		cin >> l >> r;
		int ming,maxg;
		int low = 0 , high = dev.size()-1;
        int res =-1 , mid ;
		while(high >= low)
        {
			 mid = low + (high-low+1)/2;
			if(dev[mid] <= r)
				res = mid , low = mid +1 ;
			else
				high = mid - 1; 
		}
		if(g % dev[res]==0 && dev[res] >= l) cout<< dev[res]<<endl;
		else	cout << -1 << endl;
	}
    return 0;
 
}	
 