#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

std::vector<vii> AdjList;
std::vector<int> djks_dist;

void addEdge(int u, int v,int p){
    AdjList[u].push_back(std::make_pair(v,p));
    AdjList[v].push_back(std::make_pair(u,p));
}
void djks(int u,int p){
    djks_dist[u] = p;
    for (int j = 0; j < (int)AdjList[u].size(); j++){
        int vn = AdjList[u][j].first;
        int vp = AdjList[u][j].second;
        if(djks_dist[vn] > vp + p){
            djks(vn,vp + p);
        }
    }
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
    int V,arista;
    cin>>V>>arista;
    AdjList.assign(V, vii());
    djks_dist.assign(V,MAX);
    int u,v,peso;
    for(int i = 0; i<arista; i++){
        cin>>u>>v>>peso;
        addEdge(u,v,peso);
    }
    djks(0,0);
    for (int i = 1; i < V; i++)
        cout<<djks_dist[i]<<" ";
    printf("\n");
   

    return 0;
}