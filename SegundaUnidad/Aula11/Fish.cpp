/*


https://app.codility.com/programmers/lessons/7-stacks_and_queues/

 */
#include <bits/stdc++.h>
#include <numeric>
#include <map>
#include <cmath>
#include <iterator>
#include <deque>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <algorithm>
#include <stack>
#include <climits>


using namespace std;

int solution(int A[],int B[])
{
    stack<int> aux;
    int contador=0;
    for(int i=0 ; i<5 ; i++)
    {
        if(B[i]==0)
        {
            while(aux.size()>0)
            {
                if(aux.top()>A[i])
                {
                    break;
                }
                else{
                    aux.pop();
                }
            }
            
            if(aux.empty()){
                contador++;
            }
            
        }
        else{
            aux.push(A[i]);
        }
    }
    return contador+aux.size();
}
    

int main()
{

    int A[5]={4,3,2,1,5};
    int B[5]={0,1,0,0,0};
    cout<<solution(A,B);

    return 0;

}
