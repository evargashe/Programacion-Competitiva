/* https://open.kattis.com/problems/howmanydigits
 */
#include <bits/stdc++.h>

using namespace std;

vector<double> matrix(1000000, 0);
int main()
{
    int n;
    for (int i = 1; i <= 1000000; i++)
    {
        matrix[i] += matrix[i - 1] + log10(i);
    }
    while (cin >> n)
    {
        cout << int(matrix[n] + 1) << endl;
    }
    return 0;
}