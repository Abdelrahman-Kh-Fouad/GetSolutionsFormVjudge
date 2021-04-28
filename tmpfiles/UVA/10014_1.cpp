#include <bits/stdc++.h>
using namespace std ;
int n;
double a0 , an_1;
double go (vector<double>&c , int i )
{
    if(i == 0 ) return a0 ;
    if (i==n+1)return an_1;
    return ((go(c , i-1)  +go(c,i+1))/2)-c[i];
}
int main() {
    int t ; cin>>t;
    while (t--)
    {
        cin>>n>>a0>>an_1;
        vector<double>c(n+1);
        for (int i=1 ;i <= n ;i++)
            cin>>c[i];
        printf ("%0.2f",go(c,1));
    }
    return 0;
}
