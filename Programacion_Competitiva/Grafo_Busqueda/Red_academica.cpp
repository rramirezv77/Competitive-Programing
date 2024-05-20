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
// transformamos la funcion de void a vector para devolver un vector
//  con los vertices visitados de ese subconjunto de vertices
vector<int> DFS(int startVertex, int V, Grafo& Red_academica){ 
    vector<bool>visited(V,false);
    stack<int>stack;
    vector<int>Subconjunto_computadores;// aqui se guardan los vertices que se visitan
    Subconjunto_computadores.clear();
    //Iniciar la busqueda en profundidad desde el vertice inicial
    stack.push(startVertex);
    visited[startVertex] = true;
    while(!stack.empty()){
        int currentVertex = stack.top();
        Subconjunto_computadores.push_back(currentVertex);// aqui se guardan los vertices que seran devueltos
        stack.pop(); 
        // puede cambiar adjList por la matriz
        for(int neighbor:Red_academica.adjList[currentVertex]){    
            if(!visited[neighbor]){ // aqui se visita a los vecinos
                stack.push(neighbor);
                visited[neighbor] = true; 
            }
        }
    }
    return Subconjunto_computadores; // se entrega el subconjunto de vertices

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int computadores;
    int conexiones;
    int u,v;
    cin>>computadores>>conexiones;
    Grafo Red_academica(computadores);
    for(int i = 0; i<conexiones; i++){
        cin>>u>>v;
        Red_academica.addEdge(u,v);
    }
    // vector que contiene todos los vertices para comparar
    vector<int>subconjuntos_no_visitados(computadores);
    for(int i = 0; i<computadores; i++){
        // ingresamos los vertices al vector 
        subconjuntos_no_visitados[i] = i;
    }
    int i = 0; // iteraciones del while
    int rutas_faltantes = 0; // las rutas que se necesitan para los subconjuntos
    while(!subconjuntos_no_visitados.empty()){ // mientras no este vacio el vector iterar
        // creamos otro vector que toma los vertices visitados por la funcion
        vector<int> subconjuntos_visitados = DFS(i,computadores,Red_academica);    
        // eliminamos los vertices que visitamos en el vector subconjuntos_no_visitados
        for(int i:subconjuntos_visitados){
            subconjuntos_no_visitados.erase(remove(subconjuntos_no_visitados.begin(), subconjuntos_no_visitados.end(), i), subconjuntos_no_visitados.end());
        }
        // cambiamos el vector inicial para iniciar de nuevo la busqueda
        i = subconjuntos_no_visitados[0];
        rutas_faltantes++;
        subconjuntos_visitados.clear();
    }   
    cout<<rutas_faltantes-1;// numero de subconjuntos - 1      
    return 0;
}