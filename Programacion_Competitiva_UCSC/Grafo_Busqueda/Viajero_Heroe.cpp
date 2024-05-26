#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// Definición de una matriz de caracteres llamada 'grid' con tamaño máximo MAX
char grid[MAX][MAX];
// Variables para almacenar el número de filas y columnas de la matriz
int numero_filas, numero_columnas;

// Arreglos para representar las direcciones en las que se puede mover el algoritmo de relleno (flood fill)
int dr[] = {1,-1,0,0}; // Incrementos para las filas
int dc[] = {0,0,1,-1}; // Incrementos para las columnas

// Función de relleno (flood fill)
// r: fila actual
// c: columna actual
// c1: caracter original en la matriz que se debe cambiar
// c2: nuevo caracter con el que se debe rellenar
int floodFill(int r, int c, char c1, char c2) {
    // Verificar si la posición (r, c) está fuera de los límites de la matriz
    if (r < 0 || r >= numero_filas || c < 0 || c >= numero_columnas)
        return 0; // Retornar 0 si está fuera de los límites
    if(grid[r][c] != c1 && grid[r][c] != 'D'&& grid[r][c] != 'T')
        return 0;
    // Verificar si el caracter en la posición actual es igual a c1
    int ans = 0;
    if (grid[r][c] =='T')
        ans = 100; // Retornar 0 si no es igual a c1
    if (grid[r][c] =='D')
        ans = 10;
    // Cambiar el caracter en la posición actual a c2
    grid[r][c] = c2;
    // Recorrer las 4 direcciones posibles y llamar recursivamente a floodFill
    for (int i = 0; i < 4; i++) {
        ans += floodFill(r + dr[i], c + dc[i], c1, c2);
    }
    // Retornar la cantidad total de posiciones rellenadas
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // Redirigimos la entrada desde "input.txt"
    freopen("output.txt", "w", stdout);  // Redirigimos la salida a "output.txt"
    #endif
    cin >> numero_filas >> numero_columnas;

    int start_row, start_col;
    cin >> start_row >> start_col;

    for (int i = 0; i < numero_filas; i++) {
        for (int j = 0; j < numero_columnas; j++) {
            cin >> grid[i][j];
        }
    }
    int costo = floodFill(start_row,start_col,'C','.');
    cout<<costo<<endl;
    grid[start_row][start_col] = 'X'; // DONDE EMPIEZA
    for (int i = 0; i < numero_filas; i++) {
        for (int j = 0; j < numero_columnas; j++) {
            cout << grid[i][j];
        }
        cout<<endl;
    }

    return 0;
}