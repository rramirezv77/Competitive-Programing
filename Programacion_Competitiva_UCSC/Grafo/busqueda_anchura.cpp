# include < queue >

void BFS(int startVertex){
    vector<bool>visited(V,false);
    queue<int>q;
    // Iniciar la busqueda en anchura desde el vertice inicial
    q.push(startVertex);
    visited[startVertex]=true;

    while(!q.empty()){
        int currentVertex = q.front();
        q.pop();
        // puede cambiar adjList por la matriz
        for (int neighbor:adjList[currentVertex]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor]=true;
                }
        }
    }
}
