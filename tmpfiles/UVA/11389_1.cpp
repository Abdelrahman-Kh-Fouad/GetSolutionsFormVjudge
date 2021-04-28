#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n ,d ,r ;
    while(cin>>n>>d>>r && !(n==0 && d==0 && r==0))
    {
        int first , second ; 
        int sum =0; 
        for (int i =0 ;i < n ;i++)
        {
            cin>>first>>second;
            if ( first +second > d )
                sum += r * abs(first-second);
        }
        cout<<sum<<endl;
    }
    return 0 ;
}