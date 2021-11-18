#include <bits/stdc++.h>

using namespace std;

int LCS(string a,string b,int n,int m)
{
  if(a[n-1]=='0' || b[m-1]=='0')
    return 0;
  else if(a[n-1]==b[m-1])
    return 1+LCS(a,b,n-1,m-1);
  else
    return max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
}



int main() {
  string a;
  string b;
  cin>>a>>b;

  cout<<LCS(a,b,a.size(),b.size());

}