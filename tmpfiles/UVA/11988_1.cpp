#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<char>ss;
    vector<char>x;
    vector<char>::iterator it=x.begin();
    it++;
    it+=1;

    while (!cin.eof())
    {
        ss.clear();
        string temp;
        getline(cin , temp);
        int n = temp.length();

        bool f= 0;
        list <char>::iterator start=ss.begin();

        for (int i =0 ;i <n ; i++)
        {
            if (temp[i]=='[')
            {
                f=1;
                start= ss.begin();
                continue;
            }
            if (temp[i]==']')
            {
                start =ss.begin();
                f=0;
                continue;
            }
            if (f)
            {

                ss.insert(start , temp[i] );
            }
            else
            {
                ss.push_back(temp[i]);
            }

        }
        for (auto i :ss)
            cout<<i;
        cout<<endl;

    }
    return 0;
}