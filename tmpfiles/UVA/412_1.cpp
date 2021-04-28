#include <bits//stdc++.h>
using namespace std ;

int main() {
    int n;

    set <pair<int,int>>com;
    pair<int ,int > temp1,temp2;

    while (1)
    {
        cin >>n;
        if(n==0)
            return 0;
        int arr[n];
        for (int i =0 ;i <n ;i++)
            cin >>arr[i];

        int set=0;
        for (int i =0 ;i < n;i++)
        {
            for (int j =0 ;j<n ;j++)
            {
                if (arr[j]==arr[i])
                    continue;

                temp1=make_pair(arr[i],arr[j]);
                temp2=make_pair(arr[j],arr[i]);
                if (!(com.count( temp1) || com.count(temp2)))
                {
                    com.insert(temp1),set++;

                }
            }
        }


        int sum =0 ;
        for (auto i :com)
        {
            if (__gcd(i.first,i.second) ==1)
                sum++;
        }

        if (sum==0)
            cout<<"No estimate for this data set."<<endl;
        else
            cout<<fixed<<setprecision(6)<<(double)sqrt((6*set)/sum)<<endl;
        com.clear();
    }
    return 0;
}
