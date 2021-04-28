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
int main() {
	ll n , d ;
	while(cin>>n>>d)
	{
		for (int i =1 ; i < d ; i++)
		{
			i+=n;
			n++;
		}
		cout<<n <<endl;
	}
	return 0;
}
