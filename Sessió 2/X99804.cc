#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool esta_posicio_correcta(vector<int>& pos, int j){
    int n = pos.size();
    for (int k = 0; k < n; ++k) {
        if(pos[k] == j) return true;
    }
    return false;
}

bool comp(Estudiant a, Estudiant b) {
    if(a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
    else return a.consultar_DNI() < b.consultar_DNI();
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
    
    vector<Estudiant> v(M);
    
    for (int i = 0; i < M; ++i){
        v[i].llegir();
        double suma = 0;
        if(esta_posicio_correcta(pos,0)){
            suma += v[i].consultar_nota();
        }
        
        for (int j = 1; j < N; ++j){
            double nota;
            cin >> nota;
            if(esta_posicio_correcta(pos,j)){
                suma += nota;
            }
        }
        double mitj = suma/S;
        v[i].modificar_nota(mitj);
    }
    
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < M; ++i){
        v[i].escriure();
    }
}