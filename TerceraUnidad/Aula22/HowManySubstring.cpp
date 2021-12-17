/* https://www.beecrowd.com.br/judge/en/problems/view/1530
 */

#include <bits/stdc++.h>
using namespace std;

const int MN = 200011;

struct estado
{
    int tam, enlazar;
    long long numeros_caminos;
    map<int, int> siguiente;
};

estado matrix[MN << 1];
int xx, ultimo;
long long caminos;

void ad_Extends(int c)
{
    int cur = xx++;
    matrix[cur].tam = matrix[ultimo].tam + 1;
    matrix[cur].siguiente.clear();
    matrix[cur].numeros_caminos = 0;
    int p;
    for (p = ultimo; p != -1 && !matrix[p].siguiente.count(c); p = matrix[p].enlazar)
    {
        matrix[p].siguiente[c] = cur;
        matrix[cur].numeros_caminos += matrix[p].numeros_caminos;
        caminos += matrix[p].numeros_caminos;
    }

    if (p == -1)
    {
        matrix[cur].enlazar = 0;
    }
    else
    {
        int q = matrix[p].siguiente[c];
        if (matrix[p].tam + 1 == matrix[q].tam)
        {
            matrix[cur].enlazar = q;
        }
        else
        {
            int clone = xx++;
            matrix[clone].tam = matrix[p].tam + 1;
            matrix[clone].siguiente = matrix[q].siguiente;
            matrix[clone].numeros_caminos = 0;
            matrix[clone].enlazar = matrix[q].enlazar;
            for (; p != -1 && matrix[p].siguiente[c] == q; p = matrix[p].enlazar)
            {
                matrix[p].siguiente[c] = clone;
                matrix[q].numeros_caminos -= matrix[p].numeros_caminos;
                matrix[clone].numeros_caminos += matrix[p].numeros_caminos;
            }
            matrix[q].enlazar = matrix[cur].enlazar = clone;
        }
    }
    ultimo = cur;
}

int main()
{

    string line;
    while (cin >> line)
    {
        xx = 1;
        ultimo = 0;
        matrix[0].tam = 0;
        matrix[0].enlazar = -1;
        matrix[0].siguiente.clear();
        matrix[0].numeros_caminos = 1;
        caminos = 0;
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == '?')
                cout << caminos << "\n";
            else
            {
                int cur = xx++;
                matrix[cur].tam = matrix[ultimo].tam + 1;
                matrix[cur].siguiente.clear();
                matrix[cur].numeros_caminos = 0;
                int p;
                for (p = ultimo; p != -1 && !matrix[p].siguiente.count(line[i]); p = matrix[p].enlazar)
                {
                    matrix[p].siguiente[line[i]] = cur;
                    matrix[cur].numeros_caminos += matrix[p].numeros_caminos;
                    caminos += matrix[p].numeros_caminos;
                }

                if (p == -1)
                {
                    matrix[cur].enlazar = 0;
                }
                else
                {
                    int q = matrix[p].siguiente[line[i]];
                    if (matrix[p].tam + 1 == matrix[q].tam)
                    {
                        matrix[cur].enlazar = q;
                    }
                    else
                    {
                        int clone = xx++;
                        matrix[clone].tam = matrix[p].tam + 1;
                        matrix[clone].siguiente = matrix[q].siguiente;
                        matrix[clone].numeros_caminos = 0;
                        matrix[clone].enlazar = matrix[q].enlazar;
                        for (; p != -1 && matrix[p].siguiente[line[i]] == q; p = matrix[p].enlazar)
                        {
                            matrix[p].siguiente[line[i]] = clone;
                            matrix[q].numeros_caminos -= matrix[p].numeros_caminos;
                            matrix[clone].numeros_caminos += matrix[p].numeros_caminos;
                        }
                        matrix[q].enlazar = matrix[cur].enlazar = clone;
                    }
                }
                ultimo = cur;
            }
        }
    }
    return 0;
}

