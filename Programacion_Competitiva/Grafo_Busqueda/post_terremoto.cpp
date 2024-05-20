#include<bits/stdc++.h>
using namespace std;

class Grafo{
     public:
     int V; // numero de vertices
     vector<vector<int >>adjList; // lista de adyacencia
     Grafo (int vertices ){
          V = vertices;
          adjList.resize(V);
     }
     void addEdge (int u,int v){
          adjList[u].push_back(v);
          adjList[v].push_back(u);
     }
};



int main(){
    
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout);  
     #endif
    
     int vertices,aristas;
     int u,v;
     cin>>vertices>>aristas;
     Grafo grafo1(vertices);
     for(int i = 0; i<aristas; i++){
          cin>>u>>v;
          grafo1.addEdge(u-1,v-1);
     }

     int numero_rutas_verificar,Tamaño_de_ruta;
     cin>>numero_rutas_verificar;
     vector<int>ruta;
     for(int i = 0; i<numero_rutas_verificar; i++){
          cin>>Tamaño_de_ruta;
          ruta.resize(Tamaño_de_ruta);
          for(int j = 0; j<Tamaño_de_ruta; j++){
               cin>>ruta[j];
               ruta[j]=ruta[j]-1;
          }
          int contador = 1;
          for(int j = 0; j<Tamaño_de_ruta-1; j++){
               cout<<"j="<<j<<endl;
               for(int vecino : grafo1.adjList[ruta[j]]){
                    cout<<"j="<<j<<" ,ruta[j]="<<ruta[j]<<", "<<"vecino="<<vecino<<endl;
                    if(ruta[j+1] == vecino){
                         contador++;
                    } }
          }
          cout<<"contador"<<contador<<endl;
          cout<<"long"<<Tamaño_de_ruta<<endl;
          
          cout<<grafo1.adjList[0].size()<<endl;    
     }
     return 0;    
}