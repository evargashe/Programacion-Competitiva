/* https://open.kattis.com/problems/downtime
 */
#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <math.h>
#include <iterator>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void sortion(map<int, int>& M)
{

    multimap<int, int> MM;
    for (auto& it : M) {
        MM.insert({ it.first, it.second });
    }
    /*cout<<"imprimir"<<endl;
    for (auto& it : MM) {
        cout << it.first << ' '
             << it.second << endl;
    }*/
}

int main()
{

/*
7 2
1000 1010 1500 1999 2000 2010 2999

*/

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    float K;
    cin>>N;
    cin>>K;
    map<int,int> arr;
    for(int i=0;i<N;i++)
    {
        int dato;
        cin>>dato;
        arr.insert(pair<int,int>(dato,0));
    }


    vector<int> a(N);
    int j=0;
    for (auto itr = arr.begin(); itr != arr.end(); ++itr) {
        int aux=(itr->first)+1000;
        //map<int, string>::iterator it2 = arr.find((itr->first)+1000);
        //map<int, string>::iterator it = arr.find((itr->first));
        if(arr.find(aux)!=arr.end()){
            continue;
        }
        else{
            a[j]=aux;
            j++;
        }
        
    }

    for(int i=0;i<a.size();i++){
        if(a[i]!=0){
            arr.insert(pair<int,int> (a[i],0));
        }
    }

    sortion(arr);
    int i=0;
    for (auto itr = arr.begin();  i<arr.size(); ++itr,i++) {
        map<int, int>::iterator it = arr.find(itr->first);
        map<int, int>::iterator it2 = arr.find((itr->first)+1000);
        if(arr.find(itr->first)!=arr.end() && arr.find(itr->first + 1000)!=arr.end())
        {
            it->second +=1;
            it2->second -=1;
        }
    }

    

    vector<int> salida(arr.size());
    auto cont=0;
    int m=0;
    for (auto itr = arr.begin(); itr!=arr.end() ,m<salida.size() ; ++itr,m++)
    {
        cont+=itr->second;
        salida[m]=cont;
    }

    cout<<round(*max_element(salida.begin(), salida.end())/K);
    return 0;
}
