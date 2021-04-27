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
        int n ; cin>>n ;
        vector<pair<int ,int >>arr(n);
        for(int i =0 ;i  <n ;i++)cin>>arr[i].ff , arr[i].ss = i ;
        vector<int>res(n , -1 ) ; 
        sort(all(arr));
        int max_ind =-1 ;
        for(int i =0 ;i  <n ;i++)
        {
            if(max_ind > arr[i].ss) res[arr[i].ss] =max_ind ;
            max_ind = max(max_ind , arr[i].ss);
        }
        for(int i =0 ;i < n ;i++)
            cout<<(res[i]==-1 ? -1 : res[i] -i -1  )<<" ";
        cout<<endl;
     
    }
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        solve();
        return 0 ; 
    }   