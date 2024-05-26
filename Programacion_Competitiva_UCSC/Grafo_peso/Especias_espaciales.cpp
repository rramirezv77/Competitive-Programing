#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
typedef std::pair<float,float> ii;
typedef std::vector<ii> vii;

std::vector<vii> AdjList;
std::vector<float> djks_dist;

void addEdge(float u, float v,float p){
    AdjList[u].push_back(std::make_pair(v,p));
    AdjList[v].push_back(std::make_pair(u,p));
}
void djks(int u,float p){
    djks_dist[u] = p;
    for (float j = 0; j < (float)AdjList[u].size(); j++){
        float vn = AdjList[u][j].first;
        float vp = AdjList[u][j].second;
        if(djks_dist[vn] > vp + p){
            djks(vn,vp + p);
        }
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    int personas,rutas;
    int x,y;
    int u,v;
    cin>>personas>>rutas;
    AdjList.assign(personas, vii());
    djks_dist.assign(personas,MAX);
    // Crear un vector de pairs de enteros y cadenas
    vector<pair<int, int>> Coordenadas_de_las_personas;
    for(int i = 0; i<personas; i++){
        cin>>x>>y;
        Coordenadas_de_las_personas.push_back(std::make_pair(x, y));
    }
    // Acceder y mostrar los elementos del vector con sus posiciones
    // for (size_t i = 0; i < Coordenadas_de_las_personas.size(); ++i) {
    //     const auto& [primero, segundo] = Coordenadas_de_las_personas[i];
    //         cout << "Posición " << i << ": Par: " << primero << ", " << segundo << endl;
    // }
    for(int i = 0; i<rutas; i++){
        cin>>u>>v;
        float potencia_x = (Coordenadas_de_las_personas[v].first-Coordenadas_de_las_personas[u].first)*(Coordenadas_de_las_personas[v].first-Coordenadas_de_las_personas[u].first);
        float potencia_y = (Coordenadas_de_las_personas[v].second-Coordenadas_de_las_personas[u].second)*(Coordenadas_de_las_personas[v].second-Coordenadas_de_las_personas[u].second);
        float peso = sqrt(potencia_x+potencia_y);
        //cout<<potencia_x<<endl;
        //cout<<potencia_y<<endl;
        //cout<<peso<<endl;
        addEdge(u,v,peso);
    }
    djks(0,0); // inicializamos en el nodo inicial siempre con peso 0
    cout << fixed << setprecision(4); // definimos la cantidad de decimales 
    for (float i = 1; i < personas; i++)
        cout<<djks_dist[i]<<" ";
    printf("\n");
    
    return 0;
}