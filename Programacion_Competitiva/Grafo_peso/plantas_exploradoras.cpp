#include<bits/stdc++.h>
using namespace std;
// Definición de tipos y constantes
typedef std::pair<int, int> ii;  // Tipo para representar un par de enteros
typedef std::queue<ii> qii;      // Tipo para representar una cola de pares de enteros
#define MAX 1000                  // Constante para definir el tamaño máximo

// Variables globales
int grid[MAX][MAX];               // Matriz bidimensional
int numero_filas, numero_columnas;// Número de filas y columnas de la matriz
int xi, xf, yi, yf;               // Coordenadas inicial y final

// Desplazamientos en las direcciones (derecha, abajo, izquierda, arriba)
int dr[] = {1, 0, -1, 0};  // desplazamientos en las filas
int dc[] = {0, 1, 0, -1};  // desplazamientos en las columnas

// Función de búsqueda en amplitud modificada para rellenar área
int BFSfloodFill(int r, int c, int c1) {
    qii fila;
    grid[r][c] = 1;               // Marcamos la celda inicial como visitada
    fila.push(std::make_pair(r, c));  // Agregamos la celda inicial a la cola

    while (!fila.empty()) {       // Mientras la cola no esté vacía
        r = fila.front().first;   // Extraemos la fila de la celda actual
        c = fila.front().second;  // Extraemos la columna de la celda actual
        fila.pop();               // Eliminamos la celda actual de la cola
        //cout<<grid[r][c]<<" ";
        if (r == xf && c == yf)   // Si hemos alcanzado la posición final
            return grid[r][c];     // Devolvemos la distancia acumulativa de esa celda

        for (int i = 0; i < 4; i++) {  // Exploramos las celdas adyacentes
            int rv = r + dr[i], cv = c + dc[i];
                    
            // Verificamos límites de la matriz
            if (rv < 0 || rv >= numero_filas || cv < 0 || cv >= numero_columnas)
                continue;

            // Verificamos si la celda es del mismo color
            if (grid[rv][cv] != c1)
                continue;

            // Marcamos la celda y la agregamos a la cola
            grid[rv][cv] = grid[r][c] + 1;
            fila.push(std::make_pair(rv, cv));
        }
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);   // Redirigimos la entrada desde "input.txt"
        freopen("output.txt", "w", stdout);  // Redirigimos la salida a "output.txt"
    #endif

    // Lectura de dimensiones y coordenadas
    scanf("%d %d", &numero_filas, &numero_columnas);
    scanf("%d %d", &xi, &yi);
    scanf("%d %d", &xf, &yf);

    // Lectura de la matriz y ajuste de obstáculos
    for (int i = 0; i < numero_filas; i++)
        for (int j = 0; j < numero_columnas; j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 1)
                grid[i][j] = -1;
        }

    // Llamada a la función y salida de resultados
    printf("%d", BFSfloodFill(xi, yi, 0) - 1);

    return 0;
}