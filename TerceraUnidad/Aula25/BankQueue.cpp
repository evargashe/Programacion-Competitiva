/* https://open.kattis.com/problems/bank
 */

#include <bits/stdc++.h>

using namespace std; 
struct Persona{
    int dinero;
    int tiempo;
    
    Persona(int m, int w){
        dinero = m;
        tiempo = w;
    }
};

bool compararMonedas(const Persona &a, const Persona &b){
        return a.dinero >= b.dinero;
}

void colaPersona(vector<int> &v, Persona c){
    int i = c.tiempo;
    
    while(i >= 0){
        if(v[i] == 0){
            v[i] = c.dinero;
            return;
        }  
        i--; 
    }
}

int main(){ 
    int numPersonas, minutos, cantidadEfectivo, tiempoMinuto;
    int sum = 0;
    int i = 0;
	
    scanf("%d %d", &numPersonas, &minutos);
    
    vector<int> bQueue(minutos);
    vector<Persona> dinero;
    
    for(int i = 0; i < numPersonas; i++){
        scanf("%d %d", &cantidadEfectivo, &tiempoMinuto);
        Persona c(cantidadEfectivo, tiempoMinuto);
        
        dinero.push_back(c); 
    }
    
    sort(dinero.begin(), dinero.end(), compararMonedas);
    
    while(i < dinero.size()){
        colaPersona(bQueue, dinero[i]);
        i++;
    }
    
    for(int i = 0; i < bQueue.size(); i++){
        sum += bQueue[i];
    }
    
    printf("%d", sum); 
    return 0; 
}