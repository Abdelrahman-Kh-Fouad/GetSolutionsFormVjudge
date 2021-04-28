#include <bits/stdc++.h>
#define p pair<int,int>
#define f first
#define s second
using namespace std ;
vector<int>cubic;
p solve (int n )
{
    for (int i =0 ;i < cubic.size() ;i++)
    {
        int l=0  , r=cubic.size();
        int mid =-1 ;
        while(l <= r )
        {
            mid = l +( r-l)/2;
            if (cubic[mid] - cubic[i] == n )
                return {cbrt(cubic[i]) , cbrt(cubic[mid] )};
            else if (cubic[mid] - cubic[i] > n )
                r = mid -1;
            else
                l =mid+1;
        }
    }
    return {-1,-1};
}
int main()
{
    for (int i =1 ;i*i*i <=10000 ;i++ )
        cubic.push_back(i*i*i);
    int n ;
    while (cin>>n , n)
    {
        p res = solve(n);
        if (res.f ==-1 && res.s==-1 )
            cout<<"No solution"<<endl;
        else
            cout<<res.s <<" "<< res .f<<endl;
    }
    return 0;
}
