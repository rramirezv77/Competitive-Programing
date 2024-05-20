#include<vector>
#include<stdio.h>
#define MAX 10000
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

std::vector<vii> AdjList;
std::vector<int> djks_dist;

void addEdge(int u, int v,int p){
    AdjList[u].push_back(std::make_pair(v,p));
    AdjList[v].push_back(std::make_pair(u,p));
}
// u nodo actual y p el peso actual
void djks(int u,int p){
    // es un vector que guarda las distancias totales
    djks_dist[u] = p;
    // recorre los vecinos
    cout<<"Nodo actual: "<<u<<" y su peso actual: "<<p<<endl;
    for (int j = 0; j < (int)AdjList[u].size(); j++){
        int vn = AdjList[u][j].first; // vecino del nodo actual
        int vp = AdjList[u][j].second; // el peso del vecino del nodo actual
        cout<<" Nodo vecino: "<<vn<<" y su peso: "<<vp<<endl;
        if(djks_dist[vn] > vp + p){ // se compara la distancia anterior con la distancia nueva 
            djks(vn,vp + p); // vuelvo a tomar el dijstrak con el nodo siguiente
        }
    }
}

int main(){

    int V = 5;
    // inicializa el vector con un tamaño V y de pair vacios en cada uno de sus posiciones
    AdjList.assign(V, vii()); 
    // inicializa el vector con un tamaño V y sus posiciones de valor MAX
    djks_dist.assign(V,MAX);

    addEdge(0,1,5);
    addEdge(0,2,6);
    addEdge(1,3,2);
    addEdge(3,4,3);
    addEdge(2,3,0);

    for (int i = 0; i < AdjList.size(); i++)
    {
        printf("Nodo: %d\nVecinos: ",i);
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            printf("%d[p:%d] ",AdjList[i][j].first,AdjList[i][j].second);
        }
        printf("\n\n");
    }

    djks(3,0);
    for (int i = 0; i < V; i++)
        printf("%d ",djks_dist[i]);
    printf("\n");
    
    
    return 0;
}