
/* 
https://www.beecrowd.com.br/judge/en/problems/view/1701
 */
#include <bits/stdc++.h>
#include <cstdio>


using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    long long a, b, n;
    long long num;

    while(true) {
        num = 0;

        cin>>a>>b>>n;
        if((a == 0 && b == 0 && n == 0))
            break;

        for(int cont = 0 ; cont < n; cont++) {
            num += fib(a) * fib(b);
            a++;b++;
        }
        printf("%d\n",num);
    }

    return 0;
}