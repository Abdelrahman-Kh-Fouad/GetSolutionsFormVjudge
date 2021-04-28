#include <bits/stdc++.h>
using namespace std ;
int main() {
    long long n ;
    while (cin>>n, n!=-1)
    {
        while(n)
        {
            cout<<n%3;
            n/=3;
        }
        cout<<endl;
    }
    return 0;
}
