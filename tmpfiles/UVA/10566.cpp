#include <bits/stdc++.h>
using namespace std ;

int main() {
    double x , y ,c ;
    while(cin>>x>>y>>c)
    {
        double l =0 ;
        double r =y ;
        double mid =0 ;
        while(fabs(r-l)>0.0001)
        {
            mid = l+((r-l)/2);
            double c1 = (sqrt(x*x-mid*mid) * sqrt(y*y-mid*mid)) / (sqrt(x*x-mid*mid) + sqrt(y*y-mid*mid));
            if (fabs(c-c1 ) <0.0001)
                break;
            if (c > c1)
                r = mid;
            else if (c<c1)
                l =mid ;
        }
        printf("%0.3f \n",mid);
    }
    return 0;
}
