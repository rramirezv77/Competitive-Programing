#include<iostream>
#include <cstdio>
#include<bits/stdc++.h>
#include<vector>
#include <string>
using namespace std;
#define MAX 100001

void Lexico_minimo(char S[],int  K, int size){
     for(int i = K; i < size; i++){
        char key = S[i];
        int pt = i;
        while(true){
            if(key < S[pt-K] and pt - K >= 0){
                S[pt] = S[pt-K];
                S[pt-K] = key;
                pt -= K;
            }
            else{
                break;
            }
        }        
    }
    printf("%s",S);
}

int main(){
    
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif

     char palabra[MAX];
     int K;
    
     scanf("%s",&palabra);
     cin>>K;
     int size = strlen(palabra);
    
     Lexico_minimo(palabra,K,size);
    
     return 0;    
}