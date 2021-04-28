#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    while (cin>>n,n!=0)
    {
        vector<int>arr;
        for (int i =0 ;i <=sqrt(n) ;i++)
        {
            for (int j =0 ; j <= sqrt(n) ;j++)
            {
                long long  x = pow(2,i)*pow(3,j);
                if (x>INT_MAX)
                    break;
                if (x>=n)
                    arr.push_back(x);
            }
        }
        cout<<*min_element(arr.begin(),arr.end())<<endl;
    }
    return 0;
}
