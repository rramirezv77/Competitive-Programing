#include<bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;
std::vector<vi> AdjList;
vi dfs_num;
std::vector<vi> copia;
int ans = 0;
void addEdge(int u, int v){
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
}

void dfs(int u){
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++){
        //cout<<"nodo actual: "<<u<<endl;
        int v = AdjList[u][j];
        //cout<<"¿su vecino esta visitado? "<<v<<endl;
        if(dfs_num[v] == 0){
            //cout<<"no esta visitado el vecino: "<<v<<endl;
            dfs(v);
        }else{
            //cout<<"esta visitado el vecino: "<<v<<endl;
        }
    }
    
}
int numConexiones(int V){
    
    dfs_num.assign(V,0);
    int numCC=0;
    for(int i = 0; i < V; i++)
    {
        if(dfs_num[i] == 0){
            numCC++;
            dfs(i);
        }
    }
    return numCC;
}


void numConexiones1(int V){
    for(int j = 0; j<V; j++){
        dfs_num.assign(V,0);
        dfs_num[j] = 1;
        int numCC=0;
        for(int i = 0; i < V; i++)
        {
            if(dfs_num[i] == 0){
                numCC++;
                dfs(i);
            }
        }
        if(numCC>ans){
            cout<<j<<" es critico"<<endl;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // Redirigimos la entrada desde "input.txt"
    freopen("output.txt", "w", stdout);  // Redirigimos la salida a "output.txt"
    #endif
    int V,arista,u,v;
    cin>>V>>arista;
    AdjList.assign(V, vi());
    for(int i = 0; i<arista; i++){
        cin>>u>>v;
        addEdge(u,v);
    } 
    
    copia = AdjList;
    ans = numConexiones(V);
    //cout<<"numero de conexiones: "<<ans<<endl;
    //cout<<"--------------------"<<endl;
    numConexiones1(V);
    
   
}