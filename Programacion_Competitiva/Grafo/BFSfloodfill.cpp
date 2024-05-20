#include<bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<queue>
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
int BFSfloodFill(int r,int c,int c1){
    qii fila; // creamos una cola de prioridad para guardar las coordenadas 
    grid[r][c] = 1; // inicializamos la posicion inicial como visitado
    fila.push(std::make_pair(r,c));
    while(!fila.empty()){ // mientras fila no este vacia
        r = fila.front().first; // coordenada x
        c = fila.front().second; // coordenada y
        fila.pop(); // sacamos esas coordenandas de la fila
        if(r == xf && c == yf) // si las coordenadanas estan en el punto final
            return grid[r][c]; // se retorna ese valor
        for (int i = 0; i < 4; i++){ // se iterara todos los movientos
            int rv = r+dr[i],cv = c+dc[i]; // coordenadas vecinas se exploran
            if(rv<0 || rv>= MRow || cv<0 || cv>=MCol) // se verifica si las coordenadas vecinas estan dentro de la grilla
                continue; // si se cumple se omite ese movimiento o iteracion
            if(grid[rv][cv] != c1) // se verifica que si el vecino es distinto a lo que queremos rellenar  
                continue; // en tal caso se omite este movimiento o iteracion
            grid[rv][cv] = grid[r][c]+1; // si esta dentro de los limites y es lo que queremos rellenar se le acumula la cantidad de pasos para llegar a esa posicion y como visitada
            fila.push(std::make_pair(rv,cv)); // lo dejamos esa posicion la fila de prioridad para luego eliminarlo para que no sea revisado de nuevo           
        }
    }
    return 0;   
}


int main()
{
    #ifndef ONLINE_JUDGE
    
        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);
    
        // Printing the Output to output.txt file
        freopen("output.txt", "w", stdout);
    
    #endif

    int num;
    scanf("%d %d",&MRow,&MCol);
    scanf("%d %d",&xi,&yi);
    scanf("%d %d",&xf,&yf);

    for (int i = 0; i < MRow; i++)
        for (int j = 0; j < MCol; j++){
            scanf("%d",&grid[i][j]);
            if(grid[i][j] == 1)
                grid[i][j] = -1;
        }

    printf("%d",BFSfloodFill(xi,yi,0)-1);

    for (int i = 0; i < MRow; i++)
        for (int j = 0; j < MCol; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    
    return 0;
}