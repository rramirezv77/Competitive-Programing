#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif
    float valor;
    float IVA;
    float descuento;
    float diferencia;
    cin>>valor;
    std::cout << std::fixed << std::setprecision(2);
    if(valor > 150000){
        descuento = valor*0.25;
        diferencia = (valor - descuento);
        IVA = diferencia*0.19;
        cout<<IVA;
    }else{
        IVA = valor*0.19;
        cout<<IVA;
    }
    
    return 0;
}
