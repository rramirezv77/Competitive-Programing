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
     }
     // limpiar el grafo *opcional*
     void clear(){
          for(auto& vec : adjList){
               vec.clear();
          }
     }
};

void DFS(int startVertex, int V, Grafo& red_social){
    vector<bool>visited(V,false);
    stack<int>stack;
    vector<int>cursos_criticos; // aqui se guardan los cursos que necesitas para aprobar el semestre
    //Iniciar la busqueda en profundidad desde el vertice inicial
    stack.push(startVertex);
    visited[startVertex] = true;
    while(!stack.empty()){
        int currentVertex = stack.top();
        stack.pop();
        cout<<currentVertex;
        // puede cambiar adjList por la matriz
        for (int neighbor:red_social.adjList[currentVertex]){    
            if(!visited[neighbor]){ // aqui se visita a los vecinos
                stack.push(neighbor);
                visited[neighbor] = true;  
            }
        }
       
    }
    // ordenamos el vector de menor a mayor
    //sort(cursos_criticos.begin(),cursos_criticos.end());
    // eliminanos los numeros duplicados en el vector
    //auto it = std::unique(cursos_criticos.begin(), cursos_criticos.end());
    //cursos_criticos.erase(it, cursos_criticos.end());
    // mostramos los cursoa del vector
    //for(int i:cursos_criticos){
    //    cout<<i<<" ";
    //}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int personas;
    int conexiones;
    int minimo_de_seguidores;
    int u,v;
    cin>>personas>>conexiones>>minimo_de_seguidores;
    vector<int>influence(conexiones);
    Grafo red_social(personas);
    for(int i = 0; i<conexiones; i++){
        cin>>u>>v;
        red_social.addEdge(u,v);
        influence[i] = v;
    }
    int contador1 = 0;
    for(int i = 0; i<influence.size(); i++){
        // Utilizar std::count para contar ocurrencias
        int contador = count(influence.begin(), influence.end(), i);
        if(contador>=minimo_de_seguidores){
            contador1++;
        }
    }
    cout<<contador1;
    return 0;
}