#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n , m ; cin>>n >>m ;
    vector<vector<ll>>point(n+1 , vector<ll>() );
    for(int i =0 ;i < m ;i++){
        ll l , r , c ; 
        cin>>l >> r >>c ; 
        point[l-1].pb(c) ; 
        point[r].pb(-c); 
    }
    vector<ll>res (n , 0 );
    ll key =0; 
    map<ll,ll>colors ; 
    map<ll,vector<ll>>inds ;
    colors.insert({0 ,0 });
    inds[0].pb(0);
    key++;
    for(int i =0 ;i <=n ;i++){
        vector<ll>&val = point[i];

        for(ll el : val){
            if(el >0 ){
                colors.insert({key  , el });
                inds[el].pb(key);
                key ++; 
            }
            else if(el <0 ){
                el *=-1;
                ll lastOne = inds[el].back();
                inds[el].pop_back();
                colors.erase(lastOne);
            }
        }
        if(i < n )
        res[i] = (*colors.rbegin()).ss ;
    }
    for(ll &i : res)
        cout <<i <<endl;
    
    return 0 ; 
}