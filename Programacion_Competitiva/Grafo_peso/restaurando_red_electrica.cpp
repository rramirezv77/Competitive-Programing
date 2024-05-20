#include<bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

std::vector<vii> AdjList;
vi prim_taken;
std::priority_queue<ii> pq;

void addEdge(int u, int v,int p){
    AdjList[u].push_back(std::make_pair(v,p));
    AdjList[v].push_back(std::make_pair(u,p));
}

void process(int u){
    prim_taken[u] = 1;
    for (int i = 0; i < (int)AdjList[u].size(); i++){
        ii v = AdjList[u][i];
        if(!prim_taken[v.first])
            pq.push(ii(-v.second,-v.first));
    }
    
}

int prim(){
    process(0);
    int costo_total = 0;
    while (!pq.empty()){
        ii top = pq.top();
        pq.pop();
        if(!prim_taken[-top.second]){
            costo_total += -top.first;
            process(-top.second);
        }
    }
    return costo_total;   
}

int main(){
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
     freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
     #endif
     int V,conexiones,conexiones_seguras;
     cin>>V>>conexiones>>conexiones_seguras;
     AdjList.assign(V, vii());
     prim_taken.assign(V,0);
     int contador = 0;
     int u,v,peso;
     for(int i = 0; i<conexiones; i++){
          cin>>u>>v>>peso;
          if(contador < conexiones_seguras){
               peso = 0;
               addEdge(u,v,peso);
          }else{
               addEdge(u,v,peso);
          }
          contador++;
     }
     cout<<prim();

     return 0;
}