#include <iostream>
#include "Estudiant.hh"
#include <vector>
using namespace std;

/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
 /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
void simplificar_vector(vector<Estudiant>& v, int& pos){
    pos = 0;
    int n = v.size();
    for(int i = 1; i < n; ++i){
        if(v[pos].consultar_DNI() == v[i].consultar_DNI()){
            if(v[i].te_nota()){
                    if(v[pos].te_nota()){
                        if(v[i].consultar_nota() > v[pos].consultar_nota()){
                            v[pos].modificar_nota(v[i].consultar_nota());
                        }
                    }
                    else {                                                      //  v[pos] no te nota
                        v[pos].afegir_nota(v[i].consultar_nota());
                    }
            }
        }
        else{                                                                   //No son el mateix estudiant
            ++pos;
            v[pos] = v[i];
        }
    }
}
 
/*
int main(){
    int N;
    cin >> N;
    vector<Estudiant> v(N);
    
    for(int i = 0; i < N; ++i) v[i].llegir();
    
    int pos;
    simplificar_vector(v,pos);
    
    for(int j = 0; j < pos+1; ++j) v[j].escriure();
}
*/