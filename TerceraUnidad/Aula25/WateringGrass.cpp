/* https://open.kattis.com/problems/grass */

#include <bits/stdc++.h>
using namespace std;

struct interval{
    double a;
    double b;
    int index;

    bool operator < (interval x) const {
        return a < x.a;
    }
};

double A,B,maxx;    
int n, acumulador, mejor;
vector<int> matrix;
bool posible;

int main(){
	int n,l;
	double r,w,x;
	while (cin >> n >> l >> w){
		interval Intervalos[n];
		for (int i=0;i<n;i++){
			cin >> x >> r; 
			if (r >= w/2){
				double p = sqrt(r*r -w*w/4);
				Intervalos[i].a = x - p;
				Intervalos[i].b = x + p;
				Intervalos[i].index = i;
			}
			else {
				Intervalos[i].a = -1;
				Intervalos[i].b = -1;
				Intervalos[i].index = i;
			}
		}
		A = 0;
		B = l;

        sort(Intervalos,Intervalos+n); 
        acumulador = 0;
        matrix.clear();
        posible = true;
        
        while (Intervalos[acumulador].b < A){
            acumulador++;
            if (acumulador == n){
                posible = false;
                break;
            }
        }
        if (A == B && posible){
            if (Intervalos[acumulador].a <= A && Intervalos[acumulador].b >= A)
                matrix.push_back(Intervalos[acumulador].index);
            else posible = false;
        }
        while (A < B && posible){
            if (acumulador == n){
                posible = false;
                break;
            }
            maxx = -1;
            mejor = -1;
            while (Intervalos[acumulador].a <= A){
                if (Intervalos[acumulador].b - A > maxx){
                    maxx = Intervalos[acumulador].b - A;
                    mejor = acumulador;
                }
                acumulador++;
                if (acumulador == n) break;
            }
            if (mejor == -1){
                posible = false;
                break;
            }
            matrix.push_back(Intervalos[mejor].index);
            A = Intervalos[mejor].b;
        }
        if (!posible)
            cout << "-1" << endl;
        else{
            cout << matrix.size() << endl;

        }
	}

    return 0;
}