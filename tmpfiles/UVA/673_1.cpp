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
        bool f =1 ; 
        for (auto i :s )
        {
            if (mp[i]>0) tt.push(i);
            else 
            {
                if ( tt.empty() )
                {
                    f = 0; 
                    break;
                }
                else 
                {
                    if (mp[tt.top()]+mp[i]==0)
                        tt.pop();
                    else{
                        f= 0; 
                        break;
                    }
                } 
            }
        }
        if ( f )
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0; 
}