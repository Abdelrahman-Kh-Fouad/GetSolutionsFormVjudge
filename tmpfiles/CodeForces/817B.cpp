#include <bits/stdc++.h>
using namespace std ;
int main() {
    int n ; cin>>n;
    int arr[n];
    for(int i =0 ;i < n ;i++)
        cin>>arr[i];
    map <int,int>ch;
    for(int i =0 ;i < n ;i++)
        for (int j =i+1 ;j < n ;j++)
            for(int k =j+1 ; k <n ; k++)
                ch[arr[i]*arr[j]*arr[k]]++;
    cout<<ch.begin()->second<<endl;
    return 0;
}
