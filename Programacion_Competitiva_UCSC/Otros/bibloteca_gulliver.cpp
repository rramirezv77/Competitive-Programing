#include<bits/stdc++.h>
using namespace std;
 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int n_codigos;
    cin>>n_codigos;
    int bibloteca[n_codigos];
    int inversa_bibloteca[n_codigos];
    int conteo = n_codigos;
    for(int i = 1; i<=n_codigos; i++){
        cin>>bibloteca[i];
    }
    for(int i = 1; i<=n_codigos; i++){
        inversa_bibloteca[i] = bibloteca[conteo];
        conteo = conteo - 1;
    }
    for(int i = 1; i<=n_codigos; i++){
        cout<<inversa_bibloteca[i]<<endl;
    }
    return 0;
}
