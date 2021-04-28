#include<bits/stdc++.h>
using namespace std ;
vector<pair<pair<int,int> ,int >> points;
 map <pair<int , pair<int,int>> , double>memo;
double dp(int ind =0,int x=0 , int y=0 )
{
    int newx= points[ind].first.first;
    int newy= points[ind].first.second; 
    if(ind == points.size()-1)return sqrt((newx-x) * (newx-x) + (newy-y)*(newy-y)) +1 ; 
    
     if(memo.count({ind,{x,y}}))
         return memo[{ind,{x,y}}] ;
    double leave = dp(ind+1 , x, y ) + points[ind].second;

    
    double take = dp(ind+1 , newx , newy)  + 1 +sqrt((newx - x )*(newx - x ) + (newy-y)*(newy-y))  ;
    return  memo[{ind,{x,y}}] = min (take ,   leave );

} 
int main()
{
    int n ; 
    while(cin>>n && n !=0)
    {
        int x,y,p;
        points.clear();
        points.push_back({{0,0} , 0 });
        for(int i =0 ;i < n ;i++)
            cin>>x >>y >> p, points.push_back({{x,y} , p }) ;
        points.push_back({{100,100} , 0 });
        //memset(memo , -1 , sizeof memo );
        memo.clear();
        printf("%0.3f\n" ,dp());
    }
    return 0 ;
}