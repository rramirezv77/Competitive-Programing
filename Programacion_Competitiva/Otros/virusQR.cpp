#include<iostream>
#include <cstdio>
#include<bits/stdc++.h>
#include<vector>
#include <string>
using namespace std;

int main(){
    
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif

     int a,b,contador = 0;
    while(contador == 0){    
        scanf("%d %d",&a,&b);
        std::string QR[a];
        std::string Matriz[b];
        for(int i = 0; i<a; i++){
            cin >> QR[i];
        }
        for(int i = 0; i<b; i++){
            cin >> Matriz[i];
        }
       
        for(int i = 0; i<b-1; i++){
            for(int j = 0; j<b-1; j++){
                if(QR[0][0] == Matriz[i][j] && QR[0][1] == Matriz[i][j+1] && QR[1][0] == Matriz[i+1][j] && QR[1][1] == Matriz[i+1][j+1]){
                     contador ++;
                }
            } 
        }
        if(contador!=0){
            printf("QR infectado\n");
        }else{
            printf("QR seguro\n");
        }
     }

     return 0;
}