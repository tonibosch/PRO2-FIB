#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int pos = cerca_dicot(vest,0,nest-1,est.consultar_DNI());
    if(pos >= 0 and pos < nest and est.consultar_DNI() == vest[pos].consultar_DNI()){
        b = true;
    }
    
    else {
        b = false;
        
        for(int i = nest-1; i >= pos ;--i){
            vest[i+1] = vest[i];
        }
        vest[pos] = est;
        ++nest;
        
        if(est.te_nota()){
            suma_notes += est.consultar_nota();
            ++nest_amb_nota;
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    if(nest <= 0) throw PRO2Excepcio("Conjunt buit");
    int pos = cerca_dicot(vest,0,nest-1,dni);
    
    if(pos < nest and vest[pos].consultar_DNI() == dni){
        b = true;
        
        if(vest[pos].te_nota()){
            suma_notes -= vest[pos].consultar_nota();
            --nest_amb_nota;
        }
        
        for(int i = pos; i < nest-1 ;++i){
            vest[i]=vest[i+1];
        }
        --nest;
    }
    
    else{
        b = false;
    }
}