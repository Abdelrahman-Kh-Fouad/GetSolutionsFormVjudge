#include <bits/stdc++.h>
#define width(n) (int)(log(n)/log(10))+1
using namespace std ;

int main() {
    int n1 ,m1 ;
    while (1)
    {
        cin>>n1>>m1;
        if (n1==0 && m1 ==0)
            return  0;

        set <int>upperch ,nmch,downch;
        for (int i =1; i<=n1 ;i++)
          upperch.insert(i);
        for (int i =1; i<=(n1- m1) ;i++)
           nmch.insert(i);
        for (int i = 1 ;i <= m1 ;i++)
            downch.insert(i);


        for (auto i :upperch)
            if (downch.count(i) && i!=1)
                downch.erase(i),upperch.erase(i);
        for (auto i :upperch )
            if (nmch.count(i) && i!=1)
                nmch.erase(i),upperch.erase(i);

        unsigned long long result=1;
        for (auto i : upperch)
            result*=i;
        for (auto i :nmch)
            result/=i;

        for (auto i :downch)
            result/=i;
        cout<<result<<endl;



    }
    return 0;
}
