#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    int t ; cin>>t;
    map<char , int >mp ={{'(',1 },{')' ,-1 } ,
                        {'[' ,2 }, {']' ,-2 } ,
                        {'{' ,3 } ,{'}' ,-3 }};
    while(t--)
    {
        string s ; cin>>s;
        stack<char>tt; 
        for (auto i :s )
        {
            if (mp[i]>0)
                tt.push(i);
            else 
            {
                char tmp = tt.top();
                if(mp[tmp]+mp[i]==0)
                    tt.pop();
            }
        }
        if ( tt.empty())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0; 
}