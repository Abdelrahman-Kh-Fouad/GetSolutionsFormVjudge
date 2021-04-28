#include <bits/stdc++.h>
#define ll long long
using namespace std ;
int main() {

    int n ; double p ;
    while (cin>>n>>p)
        cout<<  round( exp( log(p)/n )) <<endl;
    return 0;
}
