#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

int main(){
    Cjt_estudiants c;
    c.llegir();
    
        int n;
        cin >> n;
        while (n != -6){
            if(n == -1){
                Estudiant e;
                e.llegir();
                if(c.existeix_estudiant(e.consultar_DNI())){
                    cout << "el estudiante " << e.consultar_DNI() << " ya estaba" << endl << endl;
                }
                else if(c.mida() != Cjt_estudiants::mida_maxima()) {
                    c.afegir_estudiant(e);
                }
                else {
                    cout << "el conjunto esta lleno" << endl << endl;
                }
            }
            
            else if(n == -2) {
                int dni_est;
                cin >> dni_est;
                
                if(c.existeix_estudiant(dni_est)){
                    Estudiant e = c.consultar_estudiant(dni_est);
                    if(e.te_nota()){
                        cout << "el estudiante " << dni_est << " tiene nota " << e.consultar_nota() << endl << endl;
                    }
                    else cout << "el estudiante " << dni_est << " no tiene nota" << endl << endl;
                }
                else {
                    cout << "el estudiante " << dni_est << " no esta" << endl << endl;
                }
            }
            
            else if(n == -3){
                Estudiant e;
                e.llegir();
                if(c.existeix_estudiant(e.consultar_DNI())){
                    c.modificar_estudiant(e);
                }
                else {
                    cout << "el estudiante " << e.consultar_DNI() << " no esta" << endl << endl;
                }
            }
            
            else if(n == -4){
                int m = c.mida();
                for (int i = 0; i < m; ++i){
                    Estudiant e = c.consultar_iessim(i+1);
                    if(e.te_nota()){
                        e.modificar_nota(redondear(e.consultar_nota()));
                        c.modificar_estudiant(e); //!
                    }
                }
            }
                
            else {
                c.escriure();
               cout << endl;
            }
            cin >> n;
        }
}