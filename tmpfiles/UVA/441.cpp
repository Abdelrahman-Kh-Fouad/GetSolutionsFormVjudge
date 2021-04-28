#include <bits/stdc++.h>
using namespace std ;
bool get_bit(int num , int bit )
{
    return (num & 1 <<bit);
}
int main() {

    int n;

    while (1)
    {
        cin>>n;
        if (n ==0)
            return 0;
        vector<int>arr(n);
        vector <string>sorted;
        set< string> check;
        for (int i =0; i<n ;i++)
            cin>>arr[i];


        int limit =pow( 2,n)-1;
        int cc=0;
        for (int i =0 ;i <limit ;i++)
        {
            vector <int>sub;
            int cnt =0;
            for (int j=n-1 ;j>=0 ;j--)
            {
                if (get_bit(i ,j) && cnt !=6)
                {
                    sub.push_back(arr[j]);
                    cnt++;
                }

            }

            sub.shrink_to_fit();
            if (sub.size()==6)
            {
                reverse(sub.begin() , sub.end());
                string temp (sub.begin() , sub.end());
                if (!check.count(temp))
                {
                    sorted.push_back(temp);
                    check.insert(temp);
                }
            }
        }
        sort(sorted.begin() , sorted.end());
        for (auto i : sorted)
        {
            for (auto j :i)
                cout<<(int)j<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}