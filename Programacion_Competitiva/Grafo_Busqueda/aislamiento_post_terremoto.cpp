#include<bits/stdc++.h>
using namespace std;

class Grafo{
    public:
        int V; // numero de vertices
        vector<vector<int>>adjMatrix; // matriz de adyacencia
        Grafo(int vertices){
            V=vertices;
            adjMatrix.resize(V,vector<int>(V,0)); //Inicializar la matriz con 0 (sin aristas )
        }
        void addEdge(int u,int v){
            adjMatrix[u][v] = 1; // 1 para arista
            adjMatrix[v][u] = 1; // Grafo no dirigido
        }
};



int main() {

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
    
    int contador = 0;
    for(int i = 0; i<vertices; i++){
        for(int j = 0; j<vertices; j++){
            if(grafo1.adjMatrix[i][j]==0){
                contador++;
            }
        }
        if(contador == vertices){
            cout<<i+1<<" ";
        }
        contador = 0;
    }
    return 0;
}