#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int n; 
    while (cin>>n)
    {
        map<int,int>mp;
        int tmp;
        for (int i =0 ;i < n ;i++)cin>>tmp , mp[tmp]++;
        int res= -1 , cnt =0 ,cur =0; 
        for (auto i : mp )
        {
            if(i.second>cnt)
                cnt = i.second , res = i.first ,cur=0;
            if(i.second == cnt)
                cur++;
        }
        printf("%d %d %d\n",res ,cnt ,cur);
    }
    return 0 ;
}