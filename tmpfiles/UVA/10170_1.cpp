//============================================================================
// Name        : uva10170.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll target )
{
	return (- 1 + ceil (sqrt(1+(8*target))))/2;
}
int main() {
	ll n , d ;
	while(cin>>n>>d)
		cout<< solve(d + n*(n+1)/2) <<endl;
	
	return 0;
}
