#include <bits/stdc++.h>

using namespace std;

int main()
{
    int temp;
    while (1)
    {
        cin>>temp;
        if (temp==0)
            break;

        cout<<((int(sqrt(temp))==sqrt(temp))?"yes":"no")<<endl;
    }

    return 0;
}
