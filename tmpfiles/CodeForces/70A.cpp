#include <bits//stdc++.h>
#define ll unsigned long long
using namespace std;
ll pow (int n )
{
    ll p =1 ;
    while(n--)
        p *=3 , p  %=(int)1e6+3;
    return p;
}
int main() {
    int n ; cin>>n;
    cout<<pow(n-1);

    return 0;
}
