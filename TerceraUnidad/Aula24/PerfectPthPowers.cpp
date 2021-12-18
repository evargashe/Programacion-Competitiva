
/* https://open.kattis.com/problems/perfectpowers
 */
#include <bits/stdc++.h>
using namespace std;

long long n, p;
bool esta, negativo;
double x;

void solve()
{
    esta = false;
    negativo = false;
    if (n < 1)
    {
        negativo = true;
        n = -n;
    }
    for (p = 31; !esta && p >= 1; p--)
    {
        x = pow(n, 1.0 / p);
        if (x - floor(x) < 0.001)
        {
            if (pow(floor(x), p) == n)
            {
                if (!negativo || p % 2)
                {
                    cout << p << endl;
                    esta = true;
                }
            }
        }
        else if (ceil(x) - x < 0.001)
        {
            if (pow(ceil(x), p) == n)
            {
                if (!negativo || p % 2)
                {
                    cout << p << endl;
                    esta = true;
                }
            }
        }
    }
}
int main()
{

    while (cin >> n && n)
    {
        solve();
    }

    return 0;
}