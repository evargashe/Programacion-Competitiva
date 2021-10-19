/*
https://cses.fi/problemset/task/2166/
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;



bool esNegativo(vector<int> a,int x,int m)
{
    bool es=false;
    for(int i=x;i<m;i++)
    {
        if(a[i]<0)
            es=true;
        else{
            es=false;
            break;
        }
    }
    return es;
}

int sumArrayMax(vector<int> a,int x,int m)
{
    int suma=0;
    int mayor=0;
    if(esNegativo(a,x,m)==true)
    {
        for(int i=x;i<m;i++)
        {
            if(a[i]>mayor)
                mayor=0;
        }
    }

    else{
        for(int i=x;i<m;i++)
        {
            cout<<a[i]<<" ";
            suma+=a[i];
            if(suma<0){

                suma=0;

            }
            if(suma>mayor)
            {
                mayor=suma;
            }
        }
        cout<<endl;

    }
    return mayor;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len;
    int q;
    cin>>len>>q;
    int dato;
    vector<int> g;
    for(int i=0;i<len;i++)
    {
        cin>>dato;
        g.push_back(dato);
    }
    vector<int> pos;
    vector<int> salida;


    while(q>0)
    {
        for(int i=0;i<3;i++){
            cin>>dato;
            pos.push_back(dato);
        }
        if(pos[0]==1){
            g[pos[1]-1] = pos[2];
        }
        if(pos[0]==2)
        {
            salida.push_back(sumArrayMax(g,pos[1]-1,pos[2]));
        }

        for(int i=0;i<len;i++)
        {
            cout<<g[i]<<" ";
        }
        cout<<endl;
        pos.clear();
        q--;
    }  
    for(auto i=salida.begin(); i!=salida.end();i++)
    {
        cout<<*i<<endl;
    }
    return 0; 

}