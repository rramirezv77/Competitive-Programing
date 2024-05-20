#include<iostream>
#include<vector>
using namespace std;
 
class Grafo {
    public:
        int V; // numero de vertices
        vector < vector <int > > adjList ; // lista de adyacencia
        Grafo (int vertices ) {
            V = vertices;
            adjList . resize ( V );
        }
        void addEdge ( int u , int v ) {
            adjList [ u ]. push_back ( v ) ;
            adjList [ v ]. push_back ( u ) ;
        }
};

int main (){
    Grafo miGrafo(5); // Un grafo con 5 vertices
    // Agregar aristas al grafo
    miGrafo.addEdge (0 , 1) ;
    miGrafo.addEdge (1 , 2) ;
    miGrafo.addEdge (2 , 3) ;
    miGrafo.addEdge (3 , 4) ;

return 0;
}
