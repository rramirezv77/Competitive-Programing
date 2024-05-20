#include<stack>
void DFS(int startVertex){
    vector<bool>visited(V,false);
    stack<int>stack;
    //Iniciar la busqueda en profundidad desde el vertice inicial
    stack.push(startVertex);
    visited[startVertex] = true;

    while(!stack.empty()){
        int currentVertex = stack.top();
        stack . pop () ;
        // puede cambiar adjList por la matriz
        for (int neighbor:adjList[currentVertex]){
            if (!visited[neighbor]){
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
