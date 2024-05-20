#include<vector>
#include<stdio.h>
#include<queue>
#define INF 100000000
typedef std::vector<int> vi;

std::vector<vi> AdjList;

void addEdge(int u, int v){
    AdjList[u].push_back(v);
    //AdjList[v].push_back(u);
}

int main(){
    int V = 6;
    int s = 0;
    AdjList.assign(V, vi());

    addEdge(0,2);
    addEdge(2,3);
    addEdge(4,5);

    for (int i = 0; i < AdjList.size(); i++)
    {
        printf("Nodo: %d\nVecinos: ",i);
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            printf("%d ",AdjList[i][j]);
        }
        printf("\n");
    }
    
    //BFS//
    vi dist(V,INF);
    dist[s] = 0;
    std::queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int j = 0; j < AdjList[s].size(); j++)
        {
            int v = AdjList[u][j];
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        
    }
    
    //End//

}