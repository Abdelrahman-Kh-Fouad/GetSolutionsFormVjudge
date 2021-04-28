#include <bits/stdc++.h>
using namespace std;

int main() {
    long long  x ,y;

    while (1)
    {
        int cnt =0;
        cin>>x>>y;
        if (x==0 && y==0)
            return 0;
        if (x==y )
        {
            cout<<"Stan wins"<<endl;
            break;
        }
        while (1)
        {
            if (x>y)
            {
                if (x/y > 1 )
                {
                    cnt++;
                    break;
                }
                else
                    x %=y ,cnt++;
            }
            else if  (x<y)
            {
                if (y/x > 1 )
                {
                    cnt++;
                    break;
                }
                else
                    y %=x ,cnt++;
            }

            if (y==0||x==0)
                break;

        }

        cout<<((cnt%2==0)? "Ollie wins" : "Stan wins" )<<endl;
    }
    return 0;
}
