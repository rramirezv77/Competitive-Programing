#include<bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);  
    #endif
    
    double pi = 3.14159265;
    double area,diametro,radio;
    cin>>diametro;
    radio = diametro/2;
    area = (radio*radio)*pi;
    cout << fixed << setprecision(2);
    cout << area;
    return 0;
}