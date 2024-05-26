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
     // limpiar el grafo *opcional*
     void clear(){
          for(auto& vec : adjList){
               vec.clear();
          }
     }
};
void DFS(int startVertex, int V, Grafo& grid){
     vector<bool>visited(V,false);
     stack<int>stack;
     //Iniciar la busqueda en profundidad desde el vertice inicial
     stack.push(startVertex);
     visited[startVertex] = true;
     int contador = 0;
     while(!stack.empty()){
          int currentVertex = stack.top();
          stack.pop();
          // puede cambiar adjList por la matriz
          for (int neighbor:grid.adjList[currentVertex]){
               if(!visited[neighbor]){
                    stack.push(neighbor);
                    visited[neighbor] = true;
                    contador++;
               }
          }
     }
     cout<<contador*2<<endl;
     contador = 0;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int casos_pruebas;
    int nodo_inicial;
    int vertices;
    int bordes;
    int u;
    int v;
    cin>>casos_pruebas;
    for(int j = 0; j<casos_pruebas; j++){
          cin>>nodo_inicial;
          cin>>vertices;
          cin>>bordes;
          Grafo grid(vertices);
          for(int i = 0; i<bordes; i++){
               cin>>u>>v;
               grid.addEdge(u,v);
          }
          DFS(nodo_inicial,vertices, grid);
          grid.clear();
    }
    return 0;
}