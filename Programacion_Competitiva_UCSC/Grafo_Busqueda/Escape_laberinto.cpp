#include<bits/stdc++.h>
using namespace std;
typedef std::pair<int,int> ii; // pair
typedef std::queue<ii> qii; // cola de prioridad que contiene pair
#define MAX 1000
//cambiar char por grid en caso de que la matriz sea de numeros
int grid[MAX][MAX]; // matriz global para recorrerla en el floodfill
int MRow,MCol; // numero de filas y numero de columnas 
int xi,xf,yi,yf; //puntos de inicio y puntos de final

int dr[] = {1,0,-1, 0}; //indica las pocisiones de la matriz
int dc[] = {0,1, 0,-1}; //son para todas las direcciones, cambiar esto y el ciclo en caso de que no lo sea
bool BFSfloodFill(int r,int c,int c1){
    qii fila; // creamos una cola de prioridad para guardar las coordenadas 
    grid[r][c] = 3; // inicializamos la posicion inicial como visitado
    fila.push(std::make_pair(r,c));
    while(!fila.empty()){ // mientras fila no este vacia
        r = fila.front().first; // coordenada x
        c = fila.front().second; // coordenada y
        fila.pop(); // sacamos esas coordenandas de la fila
        if(xf == MRow-1 && yf == MCol -1) // si las coordenadanas estan en el punto final
            return true; // se retorna ese valor
        for (int i = 0; i < 4; i++){ // se iterara todos los movientos
            int rv = r+dr[i],cv = c+dc[i]; // coordenadas vecinas se exploran
            if(rv<0 || rv>= MRow || cv<0 || cv>=MCol) // se verifica si las coordenadas vecinas estan dentro de la grilla
                continue; // si se cumple se omite ese movimiento o iteracion
            if(grid[rv][cv] == 2)
                return true;
            if(grid[rv][cv] != c1) // se verifica que si el vecino es distinto a lo que queremos rellenar  
                continue; // en tal caso se omite este movimiento o iteracion
            grid[rv][cv] = grid[r][c]+1; // si esta dentro de los limites y es lo que queremos rellenar se le acumula la cantidad de pasos para llegar a esa posicion y como visitada
            fila.push(std::make_pair(rv,cv)); // lo dejamos esa posicion la fila de prioridad para luego eliminarlo para que no sea revisado de nuevo           
        }
    }
    return false;   
}


int main()
{
    #ifndef ONLINE_JUDGE
    
        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);
    
        // Printing the Output to output.txt file
        freopen("output.txt", "w", stdout);
    
    #endif
    int n_casos;
    bool escape;
    cin>>n_casos;
    for(int k = 0; k<n_casos; k++){
        scanf("%d %d",&MRow,&MCol);
        for (int i = 0; i < MRow; i++){
            for (int j = 0; j < MCol; j++){
                scanf("%d",&grid[i][j]);
                if(grid[i][j] == 0)
                    grid[i][j] = -1;
            }
        }

            escape=BFSfloodFill(0,0,1);
            //cout<<endl;
            if(escape){
                cout<<"Escape exitoso"<<endl;
            }else{
                cout<<"No hay escapatoria"<<endl;
            }
            // for (int i = 0; i < MRow; i++){
            //     for (int j = 0; j < MCol; j++){
            //     cout<<grid[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
    }

    return 0;
}