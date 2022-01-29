#include "Estudiant.hh"
#include <vector>
#include <iostream>
using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v){
    pair<int,int> p;
    p.first = -1;
    p.second = -1;
    
    double max = -1;
    double min = 11;
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
        if(v[i].te_nota()){
            if(v[i].consultar_nota() > max){
                max = v[i].consultar_nota();
                p.first = i;
            }
            
             else if(v[i].consultar_nota() < min){
                min = v[i].consultar_nota();
                p.second = i;
            }
            
            else if(v[i].consultar_nota() == max and v[i].consultar_DNI() < v[p.first].consultar_DNI()){
                 p.first = i;
            }
            
            else if(v[i].consultar_nota() == min and v[i].consultar_DNI() < v[p.second].consultar_DNI()){
                 p.second = i;
            }
        }
    }
    return p;
}

/*
int main (){
    int N;
    cin >> N;
    vector<Estudiant> v(N);
    
    for (int i = 0; i < N; ++i){
        v[i].llegir();
    }
    
    pair<int,int> par;
    par.first = -1;
    par.second = -1;
    par = max_min_vest(v);
    
    if(par.first == -1){
        cout << "no hay ningun estudiante con nota" << endl;
    }
    else {
        cout << "estudiante con nota max: ";
        v[par.first].escriure();
        cout << endl;
        cout << "estudiante con nota min: ";
        v[par.second].escriure();
        cout << endl;
    }
}
*/