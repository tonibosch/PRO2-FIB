#include <iostream>
#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos) {
    list<int>::iterator it_uno = uno.begin();
    list<int>::const_iterator it_dos = dos.begin();
    
    while(it_uno != uno.end() and it_dos != dos.end()){
        if((*it_uno) < (*it_dos)) it_uno = uno.erase(it_uno);
        
        else if((*it_uno) == (*it_dos)){
            ++it_uno;
            ++it_dos;
        }
        
        else ++it_dos;
    }
    
    while(it_uno != uno.end()) it_uno = uno.erase(it_uno);
}
/*
 void llegir_llistes(list<int>& l) {
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        l.insert(l.end(),n);
    }
 }
 
void escriure_llistes(const list<int>& uno){
    list<int>::const_iterator it = uno.begin();
    while(it != uno.end()){
        cout << *it << endl;
        ++it;
    }
}
 
 int main () {
    list<int> uno,dos;
    llegir_llistes(uno);
    llegir_llistes(dos);
    
    inter(uno,dos);
    escriure_llistes(uno);
}
*/