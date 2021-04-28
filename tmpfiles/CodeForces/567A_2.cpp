#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, min = 0, max = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	long long nn[100000];
	memset(nn,LONG_LONG_MAX,100000);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nn[i];

	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			x1 = abs(nn[i] - nn[i - 1]);

		x2 = abs(nn[i + 1] - nn[i]);

		if (i != (n - 1))
			y2 = abs(nn[n - 1] - nn[i]);

		y1 =abs( nn[i] - nn[0]);

		if (x1 < 0)  x1 = -x1;
		if (x2 < 0)  x2 = -x2;
		if (y1 < 0)  y1 = -y1;
		if (y2 < 0)  y2 = -y2;

		if (x2 < x1 || i == 0) cout << x2 << " ";
		else cout << x1 << " ";

		if (y2 > y1) cout << y2 << endl;
		else cout << y1 << endl;
	}
	return 0;
}

