

/* https://cses.fi/problemset/task/1644
 */

#include <bits/stdc++.h>
#include <vector>
#include <numeric>

using namespace std;


void funcion(vector<int> arr,int tam,int a,int b)
{
    int suma;
    int len=tam-a;
    int primero=0;
    int mayorA=0;
    for(int i=0;i<=tam-a;i++)
    {
        suma=std::accumulate(arr.begin()+primero,arr.end()-len,0);
        if(mayorA<suma)
            mayorA=suma;
        primero+=1;
        len-=1;

    }
    int len1=tam-b;
    int primero1=0;
    int mayorB=0;
    int suma1;
    for(int i=0;i<=tam-b;i++)
    {

        suma1=std::accumulate(arr.begin()+primero1,arr.end()-len1,0);
        if(mayorB<suma1)
            mayorB=suma1;
        primero1+=1;
        len1-=1;

    }
    
    if(mayorA>mayorB)
        cout<<mayorA;
    else  
        cout<<mayorB;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tam;
    int a,b;
    cin>>tam>>a>>b;
    int dato;
    vector<int> arr;
    for(int i=0;i<tam;i++)
    {
        cin>>dato;
        arr.push_back(dato);
    }

    funcion(arr,tam,a,b);

}