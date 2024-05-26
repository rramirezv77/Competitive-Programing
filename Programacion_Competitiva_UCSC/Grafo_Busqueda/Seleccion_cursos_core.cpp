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

void DFS(int startVertex, int V, Grafo& grafo1){
    vector<bool>visited(V,false);
    stack<int>stack;
    vector<int>cursos_criticos; // aqui se guardan los cursos que necesitas para aprobar el semestre
    //Iniciar la busqueda en profundidad desde el vertice inicial
    stack.push(startVertex);
    visited[startVertex] = true;
    while(!stack.empty()){
        int currentVertex = stack.top();
        stack.pop();
        // puede cambiar adjList por la matriz
        for (int neighbor:grafo1.adjList[currentVertex]){    
            if(neighbor+1>currentVertex+1){ // reviso si el curso vecino es mayor al curso actual
                cursos_criticos.push_back(currentVertex+1); // agrego ese curso en el vector
                continue; // pasa a la siguiente iteracion
            }
            if(!visited[neighbor]){ // aqui se visita a los vecinos
                stack.push(neighbor);
                visited[neighbor] = true;  
            }
        }
       
    }
    // ordenamos el vector de menor a mayor
    sort(cursos_criticos.begin(),cursos_criticos.end());
    // eliminanos los numeros duplicados en el vector
    auto it = std::unique(cursos_criticos.begin(), cursos_criticos.end());
    cursos_criticos.erase(it, cursos_criticos.end());
    // mostramos los cursoa del vector
    for(int i:cursos_criticos){
        cout<<i<<" ";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int vertices;
    int bordes;
    int u;
    int v;
    cin>>vertices;
    cin>>bordes;
    Grafo grafo1(vertices);
    for(int i = 0; i<bordes; i++){
        cin>>u>>v;
        grafo1.addEdge(u-1,v-1);
    }
    DFS(vertices-1,vertices, grafo1);
    grafo1.clear();
    return 0;
}