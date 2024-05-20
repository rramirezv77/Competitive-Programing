#include<bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;

std::vector<vi> AdjList;
vi dfs_num;

void addEdge(int u, int v){
    //AdjList[u].push_back(v);
    AdjList[v].push_back(u);
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
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int V,arista,minimo,u,v;
    cin>>V>>arista>>minimo;
    int contador = 0;
    AdjList.assign(V, vi());
    for(int i = 0; i<arista; i++){
        cin>>u>>v;
        addEdge(u,v);
    }
    for (int i = 0; i < AdjList.size(); i++)
    {
        if(AdjList[i].size() >= minimo){
            contador++;
        }
    }
    cout<<contador<<endl;
}