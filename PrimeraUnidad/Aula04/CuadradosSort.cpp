/* Squareeachvaluein a sortedarrayand returntheoutput in sortedorder
Input: [-4, -3, 1, 2, 3]
Output: [1, 4, 9, 9, 16] */


#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* int arr[]={1,2,7,9,11,15}; */
    int arr[]={4,-3,3,2,1}; 
    auto len = end(arr) - begin(arr);

    sort(arr, arr + len);

    for(int i=0;i<len;i++){
        arr[i]=arr[i]*2;
        cout<<arr[i]<<" "; 
    }
    



    
    

}