#include <bits/stdc++.h>
using namespace std;
set <int>primes;
vector<vector<int>>res;
int n;
bool valid(vector<int>&v)
{
    for (int i =0 ;i < n;i++)
        if (!primes.count(v[i]+v[(i+1)%n]))
            return 0;
    return 1 ;
}
bool ch[17];

void go (vector<int>&v,int ind =1)
{
    if (ind==n)
    {
        if (valid(v))
            res.push_back(v);
        return;
    }
    for (int i=1 ; i <=n ;i++)
        if (!ch[i])
        {
            ch[i]++;
            v[ind]=i;
            go(v,ind+1);
            ch[i]=0;
        }
}

int main()
{
    for (int i =1 ; i <= 32;i++ )
    {
        bool f =1;
        for (int j =2 ; j*j <=i ;j++)
        {
            if (i % j ==0){
                f=0;
                break;
            }
        }
        if (f ) primes.insert(i);
    }
    ch[1]=1;
    int cnt=1;
    while (cin>>n)
    {
        vector<int>tmp(n,1);
        go(tmp);
        cout<<"Case "<<cnt<<":\n";
        for (auto i : res )
        {
            for (auto j :i )cout<<j<<" ";
            cout<<endl;
        }
        cout<<endl;
        res.clear();
    }

    return 0;
}
