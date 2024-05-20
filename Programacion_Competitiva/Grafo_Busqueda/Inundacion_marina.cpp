#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include<string>
#define MAX 1000


//cambiar char por grid en caso de que la matriz sea de numeros
char grid[MAX][MAX];
int MRow,MCol;

//int dr[] = {1,1,0,-1,-1,-1, 0, 1}; //indica las pocisiones de la matriz
//int dc[] = {0,1,1, 1, 0,-1,-1,-1}; //son para todas las direcciones, cambiar esto y el ciclo en caso de que no lo sea
void floodFill(int r,int c,char c1,char c2){ 
    if(r<0 || r>= MRow || c<0 || c>=MCol)
        return;
    if(grid[r][c] != c1)
        return;
    grid[r][c] = c2;
    if(grid[r+1][c] == 'X' && r < MRow){
        floodFill(r,c+1,c1,c2);
        floodFill(r,c-1,c1,c2);
    }
    floodFill(r + 1,c,c1,c2);
}


int main()
{
    #ifndef ONLINE_JUDGE
    
        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);
    
        // Printing the Output to output.txt file
        freopen("output.txt", "w", stdout);
    
    #endif

    int r,c;
    scanf("%d %d",&MRow,&MCol);

    for (int i = 0; i < MRow; i++){
        for (int j = 0; j < MCol; j++){
            scanf(" %c",&grid[i][j]);
            if(grid[i][j] == '*'){
                r = i;
                c = j;
                grid[i][j] = '-';
            }
        }
    }
    floodFill(r,c,'-','*');

    printf("Plano:\n");
    for (int i = 0; i < MRow; i++){
        for (int j = 0; j < MCol; j++){
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}