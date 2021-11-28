
/* 
https://www.beecrowd.com.br/judge/en/problems/view/2792
 */
#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

vector<int> ft(MAX,0);

int main(){
    int n;
    cin>>n;
    int x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        int a=x;
        int soma = 0;
        while(a > 0){
            soma += ft[a];
            a -= a & (-a);
        }
        printf("%d",x-soma);
        printf("%s",(i == n ? "\n" : " "));
        int b=x;
        while(b < MAX){
            ft[b] += 1;
            b += b & (-b);
        }
    }

    return 0;
}