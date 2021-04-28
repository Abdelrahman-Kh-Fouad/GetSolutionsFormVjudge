#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum =0;
ll cost =0 ;
ll v ,t ;
ll  res =LONG_LONG_MAX;
void go (vector<int>&f , vector<int>&c,int ind )
{
    if (ind==f.size())
        return;
    if(sum * t >=v )
        res = min(res , cost );

    sum+=f[ind];
    cost+=c[ind];
    go(f ,c ,ind+1);
    sum-=f[ind];
    cost-=c[ind];
    go(f ,c , ind+1);

}

int main() {
    int n ; cin>>n;
    vector<int >f(n) , c(n);
    for (int i =0 ;i < n ;i++)
        cin>>f[i]>>c[i];
    int m ;cin>>m;
    for (int k =1 ; k <= m ;k++)
    {
        cin>>v>>t;
        go(f ,c , 0 );
        cout<<"Case "<<k<<": ";
        if (res ==LONG_LONG_MAX)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<res<<endl;
        res=LONG_LONG_MAX;
    }


    return 0;
}
