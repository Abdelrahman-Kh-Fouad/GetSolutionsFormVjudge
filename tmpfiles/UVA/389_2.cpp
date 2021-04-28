#include <bits/stdc++.h>
using namespace std ;
int main() {
    string s ;int from ,to;
    while (cin>>s>>from>>to)
    {
        if(s=="0")
        {
            cout<<"       0"<<endl;
            continue;
        }
        reverse(s.begin() , s.end());
        long long dec=0;
        for(int i =0 ;i < s.size() ; i++)
        {
            int digit = (s[i]>='0' && s[i]<='9' )? (s[i]-'0' ):(10+abs(s[i]-'A'));
            dec+=digit*(long long )pow(from,i);
        }
        if(to == 10 )
        {
            if(floor(log10(dec))+1 >7)
                cout<<"  ERROR"<<endl;
            else
                cout<<string(7-floor(log10(dec))+1 -2, ' ')<<dec<<endl;
        }
        else
        {
            string res ="";
            while(dec)
            {
                res.push_back((dec%to >=10)?(dec%to)-10+'A' : '0'+(dec%to));
                dec/=to;
            }
            reverse(res.begin() ,res.end());
            if(res.size()>7)
                cout<<"  ERROR"<<endl;
            else
                cout<<string(7-res.size() ,' ')<<res<<endl;
        }
    }
    return 0;
}
