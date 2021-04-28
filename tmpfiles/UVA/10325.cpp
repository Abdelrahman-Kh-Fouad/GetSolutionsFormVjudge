#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n , m ;
    while(cin>>n>>m)
    {
        vector<int>arr(m);
        int cnt =0;
        for(int i =0 ;i < m ;i++)cin>>arr[i];
        for(int i =1 ;i <=n ;i++)
        {
            bool f =0;
            for(auto j : arr)
                if(i%j==0)
                    f |=1;
            if(!f)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
