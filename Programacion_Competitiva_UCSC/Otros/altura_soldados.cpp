#include<bits/stdc++.h>
using namespace std;
 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif

    float altura[5];

    while (cin >> altura[0]) {
        // Leer la secuencia de 5 números
        for (int j = 1; j < 5; j++) {
            cin >> altura[j];
        }

        // Verificar si la secuencia es creciente, decreciente o ninguno
        bool creciente = true;
        bool decreciente = true;

        for (int j = 1; j < 5; j++) {
            if (altura[j] > altura[j - 1]) {
                decreciente = false;
            } else if (altura[j] < altura[j - 1]) {
                creciente = false;
            }
        }

        // Imprimir el resultado
        if (creciente) {
            cout << "Creciente" << endl;
        } else if (decreciente) {
            cout << "Decreciente" << endl;
        } else {
            cout << "Ninguno" << endl;
        }
    }

    return 0;
}
