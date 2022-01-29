#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

bool esta_posicio_correcta(const vector<int>& pos,int j){
        int n = pos.size();
        for (int k = 0; k < n; ++k) {   
            if(pos[k] == j) return true;
        }
        return false;
}

int main (){
    int M,N,S;
    cin >> M >> N >> S;
    
    vector<int> pos(S);
    for (int i = 0; i < S; ++i){
        int x;
        cin >> x;
        pos[i] = x-1;
    }
        
    for (int i = 0; i < M; ++i){                //Fara M (nombre estudiants) iteracions
        Estudiant e;
        e.llegir();
        double suma = 0;
        if(esta_posicio_correcta(pos,0)){
            suma += e.consultar_nota();
        }
        
        for (int j = 1; j < N; ++j){
            double nota;
            cin >> nota;
            if(esta_posicio_correcta(pos,j)) {
                suma += nota;
            }
        }
        double mitj = suma/S;
        e.modificar_nota(mitj);
        e.escriure();
    }
}