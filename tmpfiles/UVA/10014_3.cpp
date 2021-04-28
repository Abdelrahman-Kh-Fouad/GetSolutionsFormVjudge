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
        for (int i=0 ;i<n  ;i++)
            cin>>c[i],sum+=(n-i)*c[i];
        printf ("%0.2f\n\n",(n*an_1 +a0-2*sum)/(n+1));
    }
    return 0;
}
