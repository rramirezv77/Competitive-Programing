#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<stdio.h>
typedef std::vector<int> vi;

std::vector<vi> AdjList;
std::vector<vi> cam_simples;
vi cam_actual;
vi dfs_num;

void addEdge(int u, int v){
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
}

void SimplePath_dfs(int u,int v){
    if(dfs_num[u] == 1)
        return;
    dfs_num[u] = 1;
    cam_actual.push_back(u);
    if(u == v){
        cam_simples.push_back(cam_actual);
        dfs_num[u] = 0;
        cam_actual.pop_back();
        return;
    }
    for (int j = 0; j < (int)AdjList[u].size(); j++){
        int next = AdjList[u][j];
        if(dfs_num[next] == 0)
            SimplePath_dfs(next,v);
    }
    cam_actual.pop_back();
    dfs_num[u] = 0;  
}

int main()
{
    #ifndef ONLINE_JUDGE
    
        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);
    
        // Printing the Output to output.txt file
        freopen("output.txt", "w", stdout);
    
    #endif

    int V,E,a,b,i,f;
    scanf("%d %d",&V,&E);
    scanf("%d %d",&i,&f);
    AdjList.assign(V, vi());
    while (E--){
        scanf("%d %d",&a,&b);
        addEdge(a,b);
    }
    dfs_num.assign(V,0);
    SimplePath_dfs(i,f);
    for (int i = 0; i < cam_simples.size(); i++){
        for (int j = 0; j < cam_simples[i].size(); j++)
            printf("%d ",cam_simples[i][j]);
        printf("\n");
    }
    
    return 0;
}