#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // Redirigimos la entrada desde "input.txt"
    freopen("output.txt", "w", stdout);  // Redirigimos la salida a "output.txt"
    #endif
    
    int n_casos,L,mitad,total_permutaciones=0;
    cin>>n_casos;
    for(int i = 0; i<n_casos; i++){
        cin >> L;
        vector<int> niños_pesos(L);
        vector<int> niños_posiciones(L);
        for(int j = 0; j<L; j++){
            cin>>niños_pesos[j];
            niños_posiciones[j] = j;
        }
        sort(niños_pesos.begin(),niños_pesos.end());
        mitad = L/2;
        do{
            float izquierda = 0;
            float derecha = 0;
            for(int k = 0; k<mitad; k++){
                izquierda = izquierda + niños_pesos[niños_posiciones[k]];
                derecha = derecha + niños_pesos[niños_posiciones[k+mitad]];
            }
            if(izquierda==derecha){
                total_permutaciones++;
            }
        }while(next_permutation(niños_posiciones.begin(),niños_posiciones.end()));
        cout<<total_permutaciones<<endl;
        total_permutaciones = 0;
    }
   
}