#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    map<string ,int >mp = {{"(" ,1 },{")",-1}, 
                            {"{" ,2 },{"}" ,-2},
                            {"[" ,3 },{"]",-3},
                            {"<",4 } ,{">" ,-4},
                            {"(*" ,5 },{"*)",-5}
                            };

    string s ; 
    while(cin>>s)
    {
        stack<pair<int,int>> t;
        bool res =1;
        for (int i =0 ;i < s.length() ;i++ )
        {
            string cur=(i<s.length()-1) ? string(s.begin()+i,s.begin()+i+2 ) :string(s.begin()+i,s.begin()+i+1 )  ; 
            bool f =0 ;
            cout<<cur <<" ";
            if(!mp.count(cur) && cur.size() ==2)
                cur = string (cur.begin() , cur.begin()+1);

             if(mp.count(cur))
            {
                if ( mp[cur] > 0 )
                    t.push({mp[cur] , i });
                else 
                {
                    if(t.empty())
                    {
                        t.push({mp[cur] , i });
                        res=0  ;break;
                    }
                    if( mp[cur] + t.top().first ==0 )
                        t.pop();
                    else 
                    {
                        res=0;    break;
                    }
                }
                if (cur.size() ==2 )
                    i++;
            }
        }
        cout<<endl;
        if( res && t.empty())
            cout<<"YES"<<endl;
        else 
            cout<<"NO "<<t.top().second+1 <<endl;   

    }
    return 0;
}