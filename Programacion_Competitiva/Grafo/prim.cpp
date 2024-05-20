#include<stdio.h>
#include<vector>
#include<queue>
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;
typedef std::vector<ii> vii;

std::vector<vii> AdjList;
// se crea un vector normal para guardar todos los nodos inicialmente no visitados
vi prim_taken; 
 // una cola de prioridad de tipo pair donde se guarda el peso y su nodo vecino
std::priority_queue<ii> pq;
// grafo de lista de adyacencia
void addEdge(int u, int v,int p){
    AdjList[u].push_back(std::make_pair(v,p));
    AdjList[v].push_back(std::make_pair(u,p));
}

void process(int u){
    // marca al nodo actual como visitado
    prim_taken[u] = 1; 
    // Haces un recorrido de los nodos vecinos del nodo actual
    for (int i = 0; i < (int)AdjList[u].size(); i++){  
        // se guarda el nodo vecino y su peso en el pair v
        ii v = AdjList[u][i];
        // se verifica si el nodo vecino no esta visitado
        if(!prim_taken[v.first]) 
            //la cola de prioridad pq almacena las aristas en orden de menor a mayor peso, 
            //y se selecciona la arista de menor peso en cada iteración del algoritmo
            //de Prim. second = peso y first = nodo vecino
            pq.push(ii(-v.second,-v.first)); 
    }
    
}

int prim(){
     // recorremos el nodo actual
    process(0);
    int costo_total = 0;
    // mientras la cola de prioridad no este vacia 
    while (!pq.empty()){
        // guardas en el pair top el peso y nodo vecino de mayor prioridad 
        ii top = pq.top(); 
        // Eliminas el pair en la cola de prioridad que tiene el peso y nodo vecino de mayor prioridad
        pq.pop();
        // se verifica que el nodo vecino de menor prioridad no este visitado 
        if(!prim_taken[-top.second]){
             // el peso menor o de menor prioridad se acumula en el contador
            costo_total += -top.first;
            // se hace el recorrido ahora con el nodo vecino de menor prioridad como nodo actual ahora
            process(-top.second); 
        }
    }
    // retorna el costo total de la distancias de menor costo
    return costo_total;    
}

int main(){

    int V = 7;
    //El vector AdjList tiene un tamaño de V,
    //y cada una de sus posiciones es un vector de pares (vii), 
    //pero inicialmente todos esos vectores están vacíos.
    //Cada posición en AdjList representa un nodo en el grafo
    AdjList.assign(V, vii());
    // Se está inicializando el vector prim_taken con V elementos,
    // y todos esos elementos se establecen en el valor 0
    prim_taken.assign(V,0);
    addEdge(0,1,2);
    addEdge(0,2,7);
    addEdge(0,3,6);
    addEdge(0,4,13);
    addEdge(0,5,5);
    addEdge(0,6,11);
    addEdge(1,2,4);
    addEdge(2,3,1);
    addEdge(3,4,15);
    addEdge(4,5,9);
    addEdge(5,6,3);
    addEdge(6,1,14);

    for (int i = 0; i < AdjList.size(); i++)
    {
        printf("Nodo: %d\nVecinos: ",i);
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            printf("%d[p:%d] ",AdjList[i][j].first,AdjList[i][j].second);
        }
        printf("\n\n");
    }

    printf("peso total con prim: %d",prim());


    
    return 0;
}