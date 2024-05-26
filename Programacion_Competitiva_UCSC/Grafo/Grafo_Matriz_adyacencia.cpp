#include < iostream >
#include < vector >
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

int main(){
    Grafo miGrafo(5);// Crear un grafo con 5 vertices
    // Agregar aristas al grafo
    miGrafo.addEdge(0,1);
    miGrafo.addEdge(1,2);
    miGrafo.addEdge(2,3);
    miGrafo.addEdge(3,4);

return 0;
}
