
/* 
https://leetcode.com/problems/find-the-middle-index-in-array/

https://leetcode.com/problems/find-pivot-index/
 */


#include <bits/stdc++.h>
#include <vector>
#include <numeric>
using namespace std;

int len;


int findMiddleIndex(vector<int>& nums)
{
    int medioMenos1=len/2;
    int medioMas1=len/2;
    int sumaRight,sumaLeft;
    cout<<"primero while"<<endl;
    while(medioMenos1>=0)
    {
        sumaLeft=std::accumulate(nums.begin(),nums.end() - medioMas1,0);
        sumaRight=std::accumulate(nums.begin() + medioMenos1 +1 , nums.end(),0);
        if(sumaRight==sumaLeft)
        {

            return medioMenos1;
            break;
        }
        medioMenos1--;
        medioMas1++;

    }


    int medioMenos2=len/2;
    int medioMas2=len/2;
    cout<<"segundo while"<<endl;
    while(medioMenos2<len)
    {
        sumaLeft=std::accumulate(nums.begin(),nums.end() - medioMas2 - 1,0);
        sumaRight=std::accumulate(nums.begin() + medioMenos2 +1 , nums.end(),0);
        
        if(sumaLeft==sumaRight)
        {
            return medioMenos2;
            break;
        }
        medioMenos2++;
        medioMas2--;


    }
    
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int arr[]={1,7,3,6,5,6};
    //int arr[]={1,2,3};
    /* int arr[]={1,7,3,6,5,6};
    auto array_length = end(arr) - begin(arr);
    int i=0;
    bool esta=false;
    for(; i<array_length;i++)
    {
        int sumLeft=0;
        int sumRight=0;
        int j=0;
        int k=i+1;
        for(; j<i ;++j)
        {
            sumLeft+=arr[j];
        }
        for(; k<array_length ;++k )
        {
            sumRight+=arr[k];
        }
        if(sumLeft==sumRight){
            esta=true;
            break;
        }
    }
    if(esta)
    {
        cout<< i ;
    }
    else{
        cout<< "-1";
    } */
    cin>>len;
    vector<int> a;
    int dato;
    for(int i=0;i<len;i++)
    {
        cin>>dato;
        a.push_back(dato);
    }

    cout<<findMiddleIndex(a);

}