/* https://open.kattis.com/problems/pikemaneasy */

#include <bits/stdc++.h>

using namespace std;

int comparar(const void *p, const void *q)
{
    int *a = (int *)p;
    int *b = (int *)q;
    return *a - *b;
}

int main()
{
    long cantidad, numProblemas, a, b, c, p, s, i, t_p;
    long matrix[10000];

    cin >> cantidad >> numProblemas >> a >> b >> c >> matrix[0];

    for (i = 1; i < cantidad; i++)
        matrix[i] = (a * matrix[i - 1] + b) % c + 1;

    qsort(matrix, cantidad, sizeof(long), comparar);

    p = 0;
    s = 0;
    t_p = 0;
    for (i = 0; i < cantidad; i++)
    {
        if (t_p + matrix[i] <= numProblemas)
        {
            p = (p + matrix[i] + t_p) % 1000000007;
            t_p += matrix[i];
            s++;
        }
        else
        {
            break;
        }
    }

    cout << s << " " << p << endl;
    return 0;
}