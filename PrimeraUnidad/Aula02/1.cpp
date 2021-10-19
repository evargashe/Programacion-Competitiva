#include <iostream>
#include <cstring>
#include <vector>
using namespace std;




int main()
{
  string cad1;
  string cad2;
  getline(cin, cad1);
  getline(cin, cad2);
  vector<int> a;
  if(cad1.length() == cad2.length())
  {
    for(int i=0; i<cad1.length() ;i++)
    {
      int contador=0;
      int aux=cad1[i];
      for(int j=0; j<cad2.length() ;j++)
      {
        if(aux==cad2[j])
        {
          contador++;
        }

      }
      if(contador==1)
        a.push_back(1);
      else
        a.push_back(0);
    }
    bool es=true;
    for (auto i = a.begin(); i != a.end(); ++i)
    {
      if(*i == 0)
      {
        es=false;
        break;
      }
    }
    if(es==false)
      cout<<" no es anagrama" ;
    else{
      cout<<" si es anagrama ";
    }

  }

  
}