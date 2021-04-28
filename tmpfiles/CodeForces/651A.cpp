#include <bits/stdc++.h>
using namespace std ;
int main() {
    int a , b ;
    cin>>a>>b;
    int m =0 ;
    if (a<=2 && b <=2 )
    {
        cout<<1 <<endl;
        return 0;
    }
     while (a > 0 && b>0 )
     {
         if (a>b )
         {
             b++;
             a-=2;
         }
         else
         {
             a++;
             b-=2;
         }
         m+=1;
     }
     cout<<m<<endl;
    return 0;
}
