#include<bits/stdc++.h>
using namespace std;
bool cumpleRegla(const vector<int>& edades) {
    // Verificar que cada niño tenga al menos un adulto al lado
    for (int i = 0; i < edades.size(); i++) {
        if (edades[i] < 18) {
            bool tieneAdultoAlLado = false;

            if (i > 0 && edades[i - 1] >= 18) {
                tieneAdultoAlLado = true;
            }
            
            if (i < edades.size() - 1 && edades[i + 1] >= 18) {
                tieneAdultoAlLado = true;
            }

            if (!tieneAdultoAlLado) {
                return false;
            }
        }
    }

    return true;
}   
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    vector<int> edades(n);
    for (int i = 0; i < n; i++) {
        cin >> edades[i];
    }

    // Ordenar las edades para facilitar la generación de permutaciones
    sort(edades.begin(), edades.end());

    // Generar permutaciones y verificar la regla
    do {
        if (cumpleRegla(edades)) {
            // Imprimir la permutación que cumple con la regla
            for (int i = 0; i < n; i++) {
                cout << edades[i] << " ";
            }
            cout << endl;
        }
    } while (next_permutation(edades.begin(), edades.end()));

    return 0;
}