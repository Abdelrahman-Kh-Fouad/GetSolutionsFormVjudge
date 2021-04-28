#include <bits//stdc++.h>
#define ll long long
using namespace std;
int main() {
   ll n ;
   while(cin>>n)
   {
       n=(n+1)/2;
       ll pre = ((n>2) ? 2*(n-3) : 0)+((n>2)?10:0);
       cout<<3*pre+(ll)(3+5+7);
       return 0;
   }
}
//2*(n-2)+10
 //