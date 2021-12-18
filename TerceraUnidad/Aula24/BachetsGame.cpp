
/* https://open.kattis.com/problems/bachetsgame
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int a[10];
    bool matrix[1000001];

    while (scanf("%d %d", &n, &m) == 2)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        matrix[0] = false;
        for (int i = 1; i <= n; i++)
        {
            matrix[i] = false;

            for (int j = 0; j < m; j++)
                if (i >= a[j] && !matrix[i - a[j]])
                {
                    matrix[i] = true;
                    break;
                }
        }

        if (matrix[n])
            cout << "Stan wins" <<endl;
        else
            cout << "Ollie wins" <<endl;
    }

    return 0;
}