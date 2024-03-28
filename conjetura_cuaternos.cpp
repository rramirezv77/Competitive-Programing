#include<bits/stdc++.h>
using namespace std;
int main(){
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
     freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
     #endif
     int a,b;
     cin>>a>>b;
     for(int i = a; i<=b; i++){
          int bit = 0;
          for(int x = a; x<=b; x++){
               for(int y = a; y<=b; y++){
                    for(int z = a; z<=b; z++){
                         if(x<=y && y<=z && bit == 0){
                              if( (x*x) + (y*y) + (z*z) == (i*i)){
                                   cout<<x<<" "<<y<<" "<<z<<" "<<i<<endl;
                                   bit = 1;
                              }
                         }
                    }
               }
          }
     }
     return 0;
}