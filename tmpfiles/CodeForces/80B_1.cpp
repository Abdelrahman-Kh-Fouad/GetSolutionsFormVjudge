#include <bits/stdc++.h>
using namespace std;
int main() {
    int h ,m;
    char t;
    cin>>h>>t>>m;
    //180 -> 6
    //x -> h
    double x =h*180/6;
    double y =m*180/30 ;
    x+=(double)m/60*30;
    cout<<x<<" "<<y<<endl;
    return 0;
}
