#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

int main (){
    int N;
    cin >> N;
    vector<Estudiant> v(N);
    
    for (int i = 0; i < N; ++i){
        v[i].llegir();
    }
    
    Estudiant e = v[0];
    vector<Estudiant> sort;
    
    for(int i = 1; i < N; ++i){
         if(e.consultar_DNI() == v[i].consultar_DNI()){
             if(v[i].te_nota()){
                 if(e.te_nota()){
                    if(e.consultar_nota() < v[i].consultar_nota()) {
                        e.modificar_nota(v[i].consultar_nota());
                    }
                 }
                 else { //e no te nota
                     e.afegir_nota(v[i].consultar_nota());
                 }
             }
         }
         else {
            sort.push_back(e);
            e = v[i];
         }
    }
    sort.push_back(e);
    
    int n = sort.size();
    for (int i = 0; i < n; ++i) {
        sort[i].escriure();
    }
}