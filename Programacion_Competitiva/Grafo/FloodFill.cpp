#include<stdio.h>
#include<string>
#define MAX 1000

// Definición de una matriz de caracteres llamada 'grid' con tamaño máximo MAX
char grid[MAX][MAX];
// Variables para almacenar el número de filas y columnas de la matriz
int numero_filas, numero_columnas;

// Arreglos para representar las direcciones en las que se puede mover el algoritmo de relleno (flood fill)
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1}; // Incrementos para las filas
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; // Incrementos para las columnas

// Función de relleno (flood fill)
// r: fila actual
// c: columna actual
// c1: caracter original en la matriz que se debe cambiar
// c2: nuevo caracter con el que se debe rellenar
int floodFill(int r, int c, char c1, char c2) {
    // Verificar si la posición (r, c) está fuera de los límites de la matriz
    if (r < 0 || r >= numero_filas || c < 0 || c >= numero_columnas)
        return 0; // Retornar 0 si está fuera de los límites

    // Verificar si el caracter en la posición actual es igual a c1
    if (grid[r][c] != c1)
        return 0; // Retornar 0 si no es igual a c1

    // Cambiar el caracter en la posición actual a c2
    grid[r][c] = c2;

    // Inicializar la variable 'ans' a 1 (contando la posición actual)
    int ans = 1;

    // Recorrer las 8 direcciones posibles y llamar recursivamente a floodFill
    for (int i = 0; i < 8; i++) {
        ans += floodFill(r + dr[i], c + dc[i], c1, c2);
    }

    // Retornar la cantidad total de posiciones rellenadas
    return ans;
}