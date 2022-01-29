#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
#include <iostream>
using namespace std;

int main(){
    Cjt_estudiants c1,c2;
    c1.llegir();
    c2.llegir();
    int n = c1.mida();
    for (int i = 0; i < n; ++i){
        Estudiant e1 = c1.consultar_iessim(i+1);
        Estudiant e2 = c2.consultar_iessim(i+1);
        
        if(e2.te_nota()){
            if(e1.te_nota()){
                if(e2.consultar_nota() > e1.consultar_nota()){
                c1.modificar_iessim(i+1, e2);
                }
            }
            else {      //Estudiant e1 no te nota
                c1.modificar_iessim(i+1, e2);
            }
            
        }
    }
    c1.escriure();
}