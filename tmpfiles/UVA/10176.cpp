#include <bits/stdc++.h>
using namespace std ;
#define getbit(n , bit ) (bool)((n) & 1<<(bit))
int main ()
{
    int m = 131071-1;
    int size = floor(log2(m))+1;
    string s ; 
    while(cin>>s)
    {
        s.pop_back();
        reverse(s.begin() , s.end());
        bool res =0;
        for(int i =0  ;i< s.length() ; i++)
        {
            if(i>=size)
                break;
            bool cur =(bool) s[i]-'0';
            res |= getbit(m , i ) & cur ;
        }
        if(!res)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}