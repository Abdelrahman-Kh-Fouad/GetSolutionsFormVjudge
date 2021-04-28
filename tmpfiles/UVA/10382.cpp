#include<bits/stdc++.h>
using namespace std ;
#define p pair<float , float > 
#define ff first 
#define ss second
bool cmp (pair<int,int>  x ,pair<int,int> y )
{
    if(fabs(x.ff - y.ff)<0.00000001 )
        return x.ss > y.ss;
    return x.ff < y.ff;
}
int main ()
{
    int n ,l , w ; 
    while(cin>>n>>l>>w)
    {
        p arr[n];
        int t1 , t2 ;
        for(int i =0 ;i < n ;i++)
        {
            cin>>t1 >>t2;
            float tmp = sqrt(t2*t2 -((float)w/2) * ((float)w/2));
            arr[i].first=t1-tmp;
            arr[i].second=t1+tmp; 
        }
        sort(arr , arr+n);
        int cnt =1;  
        float s=0 ,e=-1; 
        for(int i =0 ;i < n ;i++)
        {
            if ( arr[i].ff <= s )
                e = max(e , arr[i].ss);
            else {
                cnt++;
                s = e ; 

                if(arr[i].ff <=s )
                    e= max(e ,arr[i].ss);
                else 
                    break;
            }
            
        }   
        if(e >=l  && arr[0].ff <=0)
            cout<<cnt<<endl;
        else
            cout<<-1<<endl;            
    }
    
    return 0; 
}