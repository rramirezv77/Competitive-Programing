#include<bits/stdc++.h>
using namespace std;

typedef std::pair<int,int> ii;
typedef std::queue<ii> qii;
#define MAX 1000
//cambiar char por grid en caso de que la matriz sea de numeros
int grid[MAX][MAX];
int copia[MAX][MAX];
int MRow,MCol;
int blanco_x,blanco_y,negro_x,negro_y;
int end_x,end_y;

int dr[] = {-2,-2,-1, 1,2,2,1,-1}; //indica las pocisiones de la matriz
int dc[] = {-1,1, 2,2,1,-1,-2,-2}; //son para todas las direcciones, cambiar esto y el ciclo en caso de que no lo sea
int Blanco_BFSfloodFill(int r,int c,int c1){
    qii fila;
    grid[r][c] = 1;
    fila.push(std::make_pair(r,c));
    while(!fila.empty()){
        r = fila.front().first;
        c = fila.front().second;
        fila.pop();
        if(r == end_x && c == end_y)
            return grid[r][c];
        for (int i = 0; i < 8; i++){
            int rv = r+dr[i];
            int cv = c+dc[i];
            if(rv<0 || rv>= MRow || cv<0 || cv>=MCol)
                continue;
            if(grid[rv][cv] != c1)
                continue;
            grid[rv][cv] = grid[r][c]+1;
            fila.push(std::make_pair(rv,cv));           
        }
    }

    return 0;   
}

int Negro_BFSfloodFill(int r,int c,int c1){
    qii fila;
    copia[r][c] = 1;
    fila.push(std::make_pair(r,c));
    while(!fila.empty()){
        r = fila.front().first;
        c = fila.front().second;
        fila.pop();
        if(r == end_x && c == end_y)
            return copia[r][c];
        for (int i = 0; i < 8; i++){
            int rv = r+dr[i];
            int cv = c+dc[i];
            if(rv<0 || rv>= MRow || cv<0 || cv>=MCol)
                continue;
            if(copia[rv][cv] != c1)
                continue;
            copia[rv][cv] = copia[r][c]+1;
            fila.push(std::make_pair(rv,cv));           
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

    int blanco,negro;
    cin>>MRow>>MCol;
    cin>>blanco_x>>blanco_y;
    cin>>negro_x>>negro_y;
    cin>>end_x>>end_y;

    for (int i = 0; i < MRow; i++){
        for (int j = 0; j < MCol; j++){
            grid[i][j] = 0;
        }
    }
    int numero_obstaculos;
    int x,y;
    cin>>numero_obstaculos;
    for(int i = 0; i<numero_obstaculos; i++){
        cin>>x>>y;
        grid[x][y] = -1;        
    }
    // Copiar los datos de grid a copia
    for (int i = 0; i < MRow; i++) {
        for (int j = 0; j < MCol; j++) {
            copia[i][j] = grid[i][j];
        }
    }
    //copy(&grid[0][0], &grid[0][0] + MRow * MCol, &copia[0][0]);
    blanco=Blanco_BFSfloodFill(blanco_x,blanco_y,0)-1;
    // for (int i = 0; i < MRow; i++){
    //     for (int j = 0; j < MCol; j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //cout<<"----------------"<<endl;
    //copy(&copia[0][0], &copia[0][0] + MRow * MCol, &grid[0][0]);
    negro=Negro_BFSfloodFill(negro_x,negro_y,0)-1;
    // for (int i = 0; i < MRow; i++){
    //     for (int j = 0; j < MCol; j++){
    //         cout<<copia[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    if(blanco == -1 && negro != -1){
        cout<<"Negro";
    }
    if(blanco != -1 && negro == -1){
        cout<<"Blanco";
    }
    if(blanco != -1 && negro != -1){
        if(blanco>negro)
            cout<<"Negro";   
        if(blanco<negro)
            cout<<"Blanco";
        if(blanco==negro)
            cout<<"Empate";
    }
    return 0;
}