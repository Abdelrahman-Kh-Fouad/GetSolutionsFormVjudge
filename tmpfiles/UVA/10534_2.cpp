#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ; 
    while(cin>>n)
    {
        int memo1[n],memo2[n]; 
        int a [n];
        for(int i =0 ;i < n ;i++)cin>>a[i];
        for (int i=0; i<n; ++i) {
            memo1[i] = 1;
            for (int j=0; j<i; ++j)
                if (a[j] < a[i])
                    memo1[i] = max (memo1[i], 1 + memo1[j]);
        }
        for (int i=n-1; i>=0; i--) {
            memo2[i] = 1;
            for (int j=i; j<n; ++j)
                if (a[j] < a[i])
                    memo2[i] = max (memo2[i], 1 + memo2[j]);
        }
        int o1 =0 ,o2= 0; 
        for(int i =0 ;i <n ;i++ )
            o1 = max (memo1[i] ,o1 ) , o2 = max(memo2[i],o2);

        cout<<2*(min(o1 ,o2 )-1)+1<<endl;;

    }
    return 0 ;
}