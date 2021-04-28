#include <bits/stdc++.h>
using namespace std ;

int main() {
    int n,k;
    cin>>n>>k;
    vector <int>x (n);
    for (int i =0 ;i <n ;i++)
        cin>>x[i];
        sort(x.begin(),x.end());
    int cnt =0,done =0;
    long long  sum=0;
    int ind=-1 ;
    for (int i = 0 ; i < n-1 ;i++)
        if (x[i]<0 &&!(x[i+1]<0))
            ind=i+1;
    while (cnt<n)
    {
       if (x[cnt]<0)
       {
           if (done <=k )
               x[cnt] =-1*x[cnt],done++;
           else
               break;
           cnt++;
       }
       else
           break;
    }

    if (k > done)
    {
        if ((k-done) %2 != 0)
            if (ind=-1 )
                x[0] *=-1;
            else if (x[0]> x[ind])
                x[ind] *= -1;
            else
                x[0] *=-1;

    }
    for (int j =0 ;j <n ;j++)
        sum=sum+x[j];
    cout<<sum;

    return 0;
}
