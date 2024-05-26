#include<bits/stdc++.h>

using namespace std;

vector < vector < pair < int, int > > > lista_ad;
vector < int > vector_distancias;

void crear_lista(int n){
	for(int i = 0; i <= n; i++){
		vector_distancias.push_back(2147483647);
		vector < pair< int, int > > nodo = {};
		lista_ad.push_back(nodo);
	}
}

void agregar_vecino(int nodo1, int nodo2, int peso){
	lista_ad[nodo1].push_back(pair< int, int >(nodo2, peso));
	lista_ad[nodo2].push_back(pair< int, int >(nodo1, peso));
}
void imprimir_lista(){
	for(int i = 0; i < lista_ad.size(); i++){
		cout << i << ": ";
		for(int j = 0; j < lista_ad[i].size(); j++){
			cout << lista_ad[i][j].first << " ";
		}
		cout << endl;
	}
}


void prim(){
	vector_distancias[1] = 0;
	priority_queue<pair< int, int >, vector<pair< int, int >>, greater<pair< int, int >>> siguiente;
	siguiente.push(pair< int, int >(0, 1));
	while(!siguiente.empty()){
		int nodo = siguiente.top().second;
		int distancia = siguiente.top().first;
		siguiente.pop();
		if(distancia <= vector_distancias[nodo]){
			for(int i = 0; i < lista_ad[nodo].size(); i++){
				int vecino = lista_ad[nodo][i].first;
				int peso = lista_ad[nodo][i].second;
				if(vector_distancias[vecino] > peso){
					vector_distancias[vecino] = peso;
					siguiente.push(pair< int, int >(vector_distancias[vecino], vecino));
				}
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
		freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
	int numero_casos;
	cin >> numero_casos;
	for(int i = 0; i < numero_casos; i++){
		int n, m, nodo1, nodo2, peso;
		cin >> n >> m;
		crear_lista(n);
		for(int j = 0; j < m; j++){
			cin >> nodo1 >> nodo2 >> peso;
			agregar_vecino(nodo1, nodo2, peso);
		}
		prim();
		int suma = 0;
		for(int j = 1; j < vector_distancias.size(); j++){
			suma += vector_distancias[j];
		}
		cout << suma << endl;
		lista_ad.clear();
		vector_distancias.clear();
	}	
	return 0;
}