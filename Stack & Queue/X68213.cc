#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void retornar_llibre(vector<stack<string>>& piles){
    string llibre;
    int n_pila;
    cin >> llibre >> n_pila;
    piles[n_pila-1].push(llibre);
}

void retirar_llibres(vector<stack<string>>& piles){
    int n_ll_elim, n_pila;
    cin >> n_ll_elim >> n_pila;
    for (int i = 0; i < n_ll_elim; ++i) {
        piles[n_pila-1].pop();
    }
}

void mostrar_pila(vector<stack<string>>& piles){
    int n_pila;
    cin >> n_pila;
    
    cout << "Pila de la categoria " << n_pila << endl;
    stack<string> aux = piles[n_pila-1];
    
    while(not aux.empty()){
        cout << aux.top() << endl;
        aux.pop();
    }
    cout << endl;
}

int main () {
    int n;
    cin >> n;
    vector<stack<string>> piles(n);
    
    int x;
    while (cin >> x and x != -4) {
        if(x == -1) retornar_llibre(piles);
        else if (x == -2) retirar_llibres(piles);
        else mostrar_pila(piles);
    }
}