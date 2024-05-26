#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> pyramid; 
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif

    pyramid piramide_azteca;
    int pisos;
    int numeros_bloques;
    int bloque;
    int size;
    cin>>pisos;
    piramide_azteca.resize(pisos);

    for(int i = 0; i<pisos; i++){
        cin>>numeros_bloques;
        piramide_azteca[i].resize(numeros_bloques);
        for(int j = 0; j<numeros_bloques; j++){
            cin>>bloque;
            piramide_azteca[i][j] = bloque;
        }
    }

    sort(piramide_azteca.begin(), piramide_azteca.end(),
        [](const vector<int>& a, const vector<int>& b) {
        if (a.size() != b.size()) {
             return a.size() < b.size();
        }
        return accumulate(a.begin(), a.end(), 0) < accumulate(b.begin(), b.end(), 0);     }
    );
    
    for(int i = 0; i<pisos; i++){
        sort ( piramide_azteca[i].begin() , piramide_azteca[i].end(),greater<int>());
    }

    for(int i = 0; i<pisos; i++){
        size = piramide_azteca[i].size();
        for(int j = 0; j<size; j++){
            cout<<piramide_azteca[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
