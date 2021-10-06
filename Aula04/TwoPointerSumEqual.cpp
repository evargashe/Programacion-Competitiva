
/* Given an array of integers that is already sorted in ascending order,find two numbers 
such that they add up to a specific target  number. 
Input: [1, 2, 7, 9, 11, 15]
target: 11
Output: [1, 3] 
positions
Input: [-1, 1, 2, 3, 5]
target = 5
Output: [2, 3] positions
 */

#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    int arr[]={-1,1,2,3,5}; 
    auto len = end(arr) - begin(arr);

    int *pointer1=&arr[0];
    int *pointer2=&arr[len-1];
    int suma=5;
    int contador;
    int posicionLeft=0;
    int posicionRight=len-1;
    while(suma!=contador)
    {
        contador=(*pointer2)+(*pointer1);
        if(contador>suma){
            pointer2--;
            posicionRight--;
        }
        else if(contador<suma){
            pointer1++;
            posicionLeft++;
        }

    }
    cout<<"output"<<"["<<posicionLeft<<"]"<<","<<"["<<posicionRight<<"]"; 

}