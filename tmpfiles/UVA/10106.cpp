#include <bits/stdc++.h>

using namespace std;

int main()
{
    string  x ,y ;

    while (!cin.eof())
    {
        cin>>x>>y;
        unsigned int digit= x.length()*y.length();
        vector<int > res(digit);
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());

        for (int i=0 ;i < x.length();i++)
        {
            for (int j =0 ; j < y.length() ;j++)
            {
                res[i+j]+=(x[i]-'0')*(y[j]-'0');

            }
        }

        for (int i =0 ; i < res.size()-1 ;i++)
        {
            res[i+1]+=res[i]/10;
            res[i]%=10;

        }
        reverse(res.begin(),res.end());
        int cnt;

        for (int i =0 ;i < res.size() ;i++)
        {
            if (res[i]!=0)
            {
                cnt=i;
                break;
            }
        }
        for (int i =cnt ;i<res.size() ;i++)
            cout<<res[i];
        cout<<endl;
    }
    return 0;
}