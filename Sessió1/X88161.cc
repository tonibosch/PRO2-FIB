#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef vector<pair<int,int>> col;
typedef vector<col> Matriu;

struct inf {
    int id, gf, gc, punts;
};

//Pre: Li arriben la posicio de la matriu, els gf i gc i un vector de structs del tips clasif.  
//Post: Retorna el vector clasif amb els gf i gf de dos equips i els punts del partit.
void estadistiques_partits(vector<inf>& inf_eq, int i, int j, int x, int y) {
    inf_eq[i].gf += x;
    inf_eq[i].gc += y;
    
    inf_eq[j].gf += y;
    inf_eq[j].gc += x;
    
    if (x > y) inf_eq[i].punts += 3;                    //Equip local guanya
    else if (x < y)  inf_eq[j].punts += 3;              //Equip visitant guanya
    else {                                              //Empat
        inf_eq[i].punts += 1;
        inf_eq[j].punts += 1;
    }
}

//Pre: inf_eq >= 2;
//Post: Retorna 
void lleguir_matriu(vector<inf>& inf_eq) {
    int n = inf_eq.size();
    Matriu m (n,col(n));                                             //Cream una matriu quadrada de pars
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0) inf_eq[j].id = j+1;                                            //Condicio perque els equips siguin identificats.
                
            cin >> m[i][j].first >> m[i][j].second;                                                                         //Llegim els pars
            
            if(i != j) estadistiques_partits(inf_eq,i,j,m[i][j].first,m[i][j].second);                                      //La condicio (i != j) hi es perque un equip no pot jugar contra ell mateix.
        }
    }
}

//Funcio que ordena els equips primer per mes punts, despres per la major diferencia de gols i finalment per l'identificador mes petit.
bool comp(inf a, inf b) {
    if(a.punts != b.punts) return a.punts > b.punts;                                            //Posar abans a la clasificacio qui tengui mes punts.
    else {
        if((a.gf-a.gc) != (b.gf-b.gc)) return (a.gf-a.gc) > (b.gf-b.gc);            //Posar abans a la clasificacio qui tengui mes diferencia de gols.
        else return a.id < b.id;                                                           //Posar abans l'equip amb l'dentificador mes petit.
    }
}

//Pre: clas.size() >= 2;
//Post: escriure per pantalla la classificacio ordenada.
void escriure_classificacio(const vector<inf>& inf_eq) {
    int n = inf_eq.size();
    for (int i = 0; i < n; ++i) cout << inf_eq[i].id << " " << inf_eq[i].punts << " " << inf_eq[i].gf << " " << inf_eq[i].gc << endl;
}
            
int main () {
    int n;
    cin >> n;
    vector<inf> inf_eq(n);
    lleguir_matriu(inf_eq);
    sort(inf_eq.begin(), inf_eq.end(), comp);                
    escriure_classificacio(inf_eq);                        
}