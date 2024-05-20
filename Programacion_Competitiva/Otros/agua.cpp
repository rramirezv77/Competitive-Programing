#include<bits/stdc++.h>
using namespace std;

int main(){
    
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif
    
     int grado;
     cin>>grado;

     if(grado<0){
          cout<<"El agua estara en estado solido";
     }

     if(0<grado && grado<100){
          cout<<"El agua estara en estado liquido";
     }     
     if(grado>100){
          cout<<"El agua estara en estado gaseoso";
     }

     return 0;
}