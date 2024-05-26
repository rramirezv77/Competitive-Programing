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
void DFS(int startVertex, int V, Grafo& vecindario,const vector<char>& futbol){ 
    vector<bool>visited(V,false);
    stack<int>stack;
    //Iniciar la busqueda en profundidad desde el vertice inicial
    stack.push(startVertex);
    visited[startVertex] = true;
    //int i = 1;
    int contador = 0;
    //int contador1 = 0;
    int contador_vecinos = 0;
    vector<int>mudar_casas;
    while(!stack.empty()){
        int currentVertex = stack.top();
        stack.pop();
        //cout<<"casa: "<<currentVertex+1<<" "<<futbol[currentVertex+1]<<endl;
        // puede cambiar adjList por la matriz
        for(int neighbor:vecindario.adjList[currentVertex]){
            contador_vecinos++;   
            if(futbol[currentVertex]!=futbol[neighbor]){
            //    cout<<" vecino diferentes:"<<neighbor+1<<endl;
                contador++;
            }
            //if(futbol[currentVertex+1]==futbol[neighbor+1]){
            //    cout<<" vecino iguales:"<<neighbor+1<<endl;
            //    contador1++;
            //}  
            if(!visited[neighbor]){ // aqui se visita a los vecinos
                stack.push(neighbor);
                visited[neighbor] = true; 
            }
        }
        if(contador > contador_vecinos/2 && contador_vecinos!=0){
            //cout<<currentVertex+1<<" ";
            mudar_casas.push_back(currentVertex+1);
        }
       // cout<<contador_vecinos<<" "<<contador<<endl;
        contador_vecinos = 0;
        //cout<<contador<<endl;
        contador = 0;
    }
    sort(mudar_casas.begin(),mudar_casas.end());
    for(int i:mudar_casas){
        cout<<i<<" ";
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif

    int numero_casas;
    int numero_vecinos;
    int v;
    cin>>numero_casas;
    vector<char>futbol(numero_casas);
    Grafo vecindario(numero_casas);
    for(int i = 0; i<numero_casas; i++){
        cin>>futbol[i];
        cin>>numero_vecinos;
        for(int j = 0; j<numero_vecinos; j++){
            cin>>v;
            if(v!=0){
               vecindario.addEdge(i,v-1); 
            }else{
                vecindario.addEdge(i,v);
            }
        }
    }
    DFS(0,numero_casas,vecindario,futbol);
    

    return 0;
}