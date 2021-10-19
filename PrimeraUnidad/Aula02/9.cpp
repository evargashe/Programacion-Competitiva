#include <iostream>
using namespace std;

void  fibonnacci_iterativo(int n){

    if(n==0)
    {
      cout<<"0";
    }
    else if(n==1)
    {
      cout<<"1";
    }
    else if(n==2)
    {
      cout<<"1";
    }
    else{
      int previo2 = 1;
      int previo = 1;
      int suma = 0;
      for(int i=2;i<=n-1;i++){
          
          suma = previo+previo2;
          previo2 = previo;
          previo = suma;
          
      }
      cout<< suma <<" ";
    }
}

int main()
{
  fibonnacci_iterativo(4);
}

