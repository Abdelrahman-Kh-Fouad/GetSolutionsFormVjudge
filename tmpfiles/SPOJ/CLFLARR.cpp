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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , m ; cin>>n >>m ;
    vector<vector<int>>point(n+1 , vector<int>() );
    for(int i =0 ;i < m ;i++){
        int l , r , c ; 
        cin>>l >> r >>c ; 
        point[l-1].pb(c) ; 
        point[r].pb(-c); 
    }
    vector<int>res (n , 0 );
    int key =0 ; 
    map<int,int>colors ; 
    map<int,vector<int>>inds ;

    for(int i =0 ;i < n ;i++){
        vector<int>&val = point[i];

        for(int el : val){
            if(el >0 ){
                colors.insert({key  , el });
                inds[el].pb(key);
                key ++; 
            }
            else if(el <0 ){
                int lastOne = inds[-el].back();
                inds[-el].pop_back();
                colors.erase(lastOne);
            }
        }
        res[i] = (*colors.rbegin()).ss ;
    }
    for(int &i : res)
        cout <<i <<endl;
    
    return 0 ; 
}