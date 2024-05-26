#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

std::vector<vii> AdjList;
std::vector<int> djks_dist;
std::vector<bool> verificar;
std::vector<int> copia;
void addEdge(int u, int v,int p){
    AdjList[u].push_back(std::make_pair(v,p));
    AdjList[v].push_back(std::make_pair(u,p));
}
// u nodo actual y p el peso actual
void djks(int u,int p){
    // es un vector que guarda las distancias totales
    djks_dist[u] = p;
    // recorre los vecinos
    //cout<<"Nodo actual: "<<u<<" y su peso actual: "<<p<<endl;
    for (int j = 0; j < (int)AdjList[u].size(); j++){
        int vn = AdjList[u][j].first; // vecino del nodo actual
        int vp = AdjList[u][j].second; // el peso del vecino del nodo actual
        //cout<<" Nodo vecino: "<<vn<<" y su peso: "<<vp<<endl;
        if(djks_dist[vn] > vp + p){ // se compara la distancia anterior con la distancia nueva 
            djks(vn,vp + p); // vuelvo a tomar el dijstrak con el nodo siguiente
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int V,arista,u,v,peso;
    cin>>V>>arista;
    AdjList.assign(V, vii()); // generar los datos iniciales
    djks_dist.assign(V,MAX); // generar los datos iniciales
    verificar.assign(V,true);

    for(int i = 0; i<arista; i++){
        cin>>u>>v>>peso;
        addEdge(u,v,peso);
    }
    djks(0,0);
    copia = djks_dist;
    int copia_2;

    for(int i = 0; i<V; i++){
        for(int j = 0; j<AdjList[i].size(); j++){
            djks_dist.assign(V,MAX);
            copia_2 = AdjList[i][j].second;
            AdjList[i][j].second = MAX;
            djks(0,0);
            for(int k = 1; k<V; k++){
                if(copia[k]<djks_dist[k]){
                    verificar[k] = false;
                }
            }
            AdjList[i][j].second = copia_2;
        }
    }
    for(int i = 1; i<V; i++){
        if(verificar[i] == true){
            cout<<"El camino a optimo a "<<i<<" es de largo "<<copia[i]<<" y es robusto"<<endl;
        }else{
            cout<<"El camino a optimo a "<<i<<" es de largo "<<copia[i]<<" y no es robusto"<<endl;
        }
        
    }
  
    return 0;
}