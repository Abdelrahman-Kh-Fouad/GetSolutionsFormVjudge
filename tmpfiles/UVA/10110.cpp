#include <iostream>

using namespace std;

int main()
{
    int temp ;
    while (cin>>temp ,temp!=0)
    {
        bool f=false;
        for (int i =1 ; i<=temp ;i++)
        {
            if (temp%i==0)
                f^=1;
        }
        cout<<((f)?"yes":"no")<<endl;
    }

    return 0;
}
