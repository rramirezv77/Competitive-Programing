#include<vector>
#include<stdio.h>
typedef std::vector<int> vi;

std::vector<vi> AdjList;
vi dfs_num;

void addEdge(int u, int v){
    AdjList[u].push_back(v);
    //AdjList[v].push_back(u);
}

void dfs(int u){
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++){
        int v = AdjList[u][j];
        if(dfs_num[v] == 0)
            dfs(v);
    }
    
}

int numConexiones(int V){
    dfs_num.assign(V,0);
    int numCC=0;
    for (int i = 0; i < V; i++)
    {
        if(dfs_num[i] == 0){
            numCC++;
            dfs(i);
        }
    }
    return numCC;
    
}

int main(){
    int V = 6;
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
    
    int ans = numConexiones(V);
    printf("%d",ans);
}