#include<bits/stdc++.h>
using namespace std;

int main(){
    
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif

    char tablero[12][12];
    for(int i = 0; i<12; i++){
        for(int j = 0; j<12; j++){
            tablero[i][j] = '.';
        }
    }

    char posicion;
    int a , b , c = 0 , contador = 0;
    int A ,B;
    std::string palabra;

    for(int i = 0; i<6; i++){
        cin >> posicion;
        cin>>a;
        A = a;
        cin>>b;
        cin>>palabra;
        
        if(posicion == 'H'){
            if(12-b > palabra.size()){
                for(int j = 0; j<palabra.size(); j++){
                tablero[a][b++] = palabra[c];
                c++;
                }
            c = 0;
            }
        }
        c = 0;
        if(posicion == 'V'){
            for(int j = 0; j<=palabra.size(); j++){
                if(tablero[A++][b] == '.' || tablero[A++][b] == palabra[c]){
                    contador++;
                }
                c++;
            }
            c = 0;
            if(12-a > palabra.size() && contador == palabra.size()){
                for(int j = 0; j<palabra.size(); j++){
                tablero[a++][b] = palabra[c];
                c++;
                }
            c = 0;
            }
            contador = 0;
        }
        c = 0;
    }

    for(int i = 0; i<12; i++){
        for(int j = 0; j<12; j++){
            printf("%c",tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}