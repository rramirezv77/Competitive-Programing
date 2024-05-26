#include<bits/stdc++.h>
using namespace std;


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif

    int x,y;
    cin>>x>>y;
    char mapa[x][y];
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            cin>>mapa[i][j];
        }
    }
    for(int i = 0; i<x; i++){
        for(int j = y; j>0; j--){
            if(mapa[i][j]=='*' && mapa[i+1][j]=='-'){
                mapa[i+1][j] = '*';
                continue;
            }
            if(mapa[i][j] == '*' && mapa[i+1][j] == 'X' && mapa[i][j-1] != 'X'){
                mapa[i][j-1] = '*';
            }
        }
        for(int j = 0; j<y; j++){
            if(mapa[i][j]=='*' && mapa[i+1][j]=='-'){
                mapa[i+1][j] = '*';
                continue;
            }
            if(mapa[i][j] == '*' && mapa[i+1][j] == 'X' && mapa[i][j+1] != 'X'){
                mapa[i][j+1] = '*';
            }
        }
    }
    cout<<"Plano:"<<endl;
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            cout<<mapa[i][j];
        }
        cout<<endl;
    }
    return 0;
}