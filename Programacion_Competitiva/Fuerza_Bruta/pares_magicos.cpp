#include<bits/stdc++.h>
using namespace std;
// Este es fuerza bruta
int main(){
    
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif

    int n_casos; 
    scanf("%d",&n_casos); // primero ingreso el numero de casos
    
    for(int i = 0; i<n_casos; i++){
        
        int n;
        scanf("%d",&n); // tamaño de los arreglos
        int par_1[n],par_2[n];
        int contador = 0; // contador para el output

        for(int j = 1; j<=n; j++){
            scanf("%d",&par_1[j]);
        }// ingresar los numeros al arreglo 1
        for(int j = 1; j<=n; j++){
            scanf("%d",&par_2[j]);
        }// ingresar los numeros al arreglo 2
        for(int j = 1; j<n; j++){
            for(int k = 1; k<=n; k++){
                if(par_1[j]*par_1[k+1] == par_2[j]+par_2[k+1]){// aplico la condicion del ejercicio ai· aj = bi + bj  
                    if(j < k+1){// esto es para que no se repita pares innecesarios por ejemplo el (4,1) o (2,1)
                        contador++;
                        cout<<"("<<j<<","<<k+1<<")"<<endl; // output
                    }
                }
            }
        }
        cout<<contador<<endl;
        // se aplica el siguiente caso de prueba 
    }
    return 0;    
}