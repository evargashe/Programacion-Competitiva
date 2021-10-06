/* Given an array, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the sequence of max values of the sliding windows.
Input: [1, 3, -1, -3, 5, 3, 6, 7]
k= 3
Output: [3, 3, 5, 5, 6, 7]


https://leetcode.com/problems/sliding-window-maximum/
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;


int CuantoFalta(int a, int b)
{
    int aux=0;
    for(int i=a+1;i<=b;i++)
    {
        if(a==b)
            break;
        else
            aux+=1;
    }
    return aux;
}
void slidingWindowsMax(vector<int> g,int k,int len)
{
    for (auto i = 0; i <= len-k ; i++)
    {
        vector<int> aux;
        for(auto j=i ;j <i+k ;j++)
        {
            aux.push_back(g[j]);    	
        }

        sort(aux.begin(), aux.end());

        int contador=0;
        int medio=k/2;
        int first=0;
        int last=k-1;
        while(first<medio || last>medio)
        {
            contador+=CuantoFalta(aux[first],aux[medio]);
            contador+=CuantoFalta(aux[medio],aux[last]);
            first++;
            last--;
        }
        cout<<contador<<" ";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len;
    int k;
    cin>>len>>k;
    int dato;
    vector<int> g;
    for(int i=0;i<len;i++)
    {
        cin>>dato;
        g.push_back(dato);
    }
    slidingWindowsMax(g,k,len);

    return 0;

}