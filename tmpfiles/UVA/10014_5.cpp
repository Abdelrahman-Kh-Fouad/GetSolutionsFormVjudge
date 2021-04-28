#include <bits/stdc++.h>
using namespace std ;
int n;
double a0 , an_1;
int main() {
    int t ; cin>>t;
    while (t--)
    {
        cin>>n>>a0>>an_1;
        vector<double>c(n+2);
        double sum=0;
        for (int i=1 ;i <= n ;i++)
            cin>>c[i],sum+=i*c[i];
        printf ("%0.2f\n\n",((double)1/2*n)*(an_1+a0)-sum);
    }
    return 0;
}
