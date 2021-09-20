#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cantidad,num;

    cin>>cantidad>>num;
    int contador=0;
    for(int i=0;i<cantidad;i++){
        int k;
        cin>>k;
        if(k%num==0)
            contador++;
    }
    cout<<contador<<"\n";
}