#include <bits/stdc++.h>

using namespace std;

int main(void)
{

    string x;
    string z;
    bool state = false;
    int l;
    while(getline(cin,x)&&getline(cin,z))
    {

        vector<int> number_1;
        vector<int> number_2;
        vector<int> result(250,0);
        vector<int> tmp;

        state = false;

// Getting The First Number :

        for(int i = x.length()-1; i>=0; i--)
        {

            l = x[i]- '0';
            number_1.push_back(l);

        }

// Getting The Second Number:

        for(int i = z.length()-1; i>=0; i--)
        {

            l = z[i] - '0';
            number_2.push_back(l);

        }

        if(x == "0" || z == "0")
        {

            cout << 0 << endl;

        }

        for(int i = 0; i<(int)number_2.size(); i++)
        {

            for(int W = 0; W<i; W++)
            {

                tmp.push_back(0);

            }

            for(int j=0; j<(int)number_1.size(); j++)
            {

// Storing in a temporary Vector:

                tmp.push_back(number_1[j] * number_2[i]);

            }

// In Case That Last element in vector need another space (>=10)

            if(tmp[tmp.size()-1]>=10)
            {

                tmp.push_back(0);

            }

// shifting numbers greater than 10;

// k = 1 To prevent Segmentation-faults:

            for(int k = 1; k<(int)tmp.size(); k++)
            {

                if(tmp[k-1]>=10)
                {

                    tmp[k]+=tmp[k-1]/10;

                    tmp[k-1]%=10;

                }

            }

            for(int j= 0 ; j<(int)tmp.size(); j++)
            {

                result[j] += tmp[j];

            }

            for(int k = 1; k<(int)result.size(); k++)
            {

                if(result[k-1]>=10)
                {

                    result[k]+=result[k-1]/10;

                    result[k-1]%=10;

                }

            }


        }

        for(int i = result.size()-1; i>=0; i--)
        {

            if(state == false && result[i]!=0 )
            {

                state = true;

            }

            if(state == true)
            {

                cout << result[i];

            }

        }

        cout << endl;

// Destroying the vector and clearing memory

    }

}
