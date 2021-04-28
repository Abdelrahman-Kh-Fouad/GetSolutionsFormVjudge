#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    int T;cin>>T;
    while(T--)
    {
        int n , t , m ;
        cin>>n>>t>>m;
        int arives[m];
        for(int i =0 ;i < m ;i++)
            cin>>arives[i];
        
        int time =0 ; 
        int cnt =ceil((float)m/n);
        for (int i =n ;i < m ;i+=n)
        {
            time = max(time , arives[i]);
            time +=2*t;    
        }
        cout<<((m%n!=0)?time-arives[m%n-1]: time)  <<" "<<cnt<<endl;
    }
    return 0;
}