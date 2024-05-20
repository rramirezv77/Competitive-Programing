#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
    int n;
    cin>>n;
    int casos_pruebas[n];
    int n_suerte;
    for(int i = 0; i<n; i++){
        cin>>n_suerte;
        casos_pruebas[i] = n_suerte;
    }
    for(int i = 0; i<n; i++){
        for(int A = 0; A<=9; A++){
            for(int B = 0; B<=9; B++){
                for(int C = 0; C<=9; C++){
                    for(int D = 0; D<=9; D++){
                        if( A + B + C + D == casos_pruebas[i]){
                            cout<<A<<B<<C<<D<<" es una clave de la suerte que suma "<<casos_pruebas[i]<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}