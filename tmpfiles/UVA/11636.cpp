#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n ;
    int cnt =1;
    while (cin>>n &&n!=-1)
    {

        printf("Case %d: %d\n",cnt,(int)ceil(log2(n)));
        cnt++;
    }
    return 0;
}
