/* https://open.kattis.com/problems/growlinggears
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        double maximoA = -INFINITY;
        int maximoB = 0;

        for (size_t i = 1; i <= k; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            double temporal = (double)b / (a << 1);
            double value = -a * temporal * temporal + b * temporal + c;

            if (value > maximoA)
            {
                maximoA = value;
                maximoB = i;
            }
        }
        cout << maximoB << endl;
    }

    return 0;
}