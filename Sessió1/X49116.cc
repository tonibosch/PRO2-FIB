#include <iostream>
#include <utility>
#include <vector>
using namespace std;
 
struct parint {
    int prim, seg;
};
 
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 parint max_min1(const vector<int>& v) {
     parint p;
     p.prim = v[0];
     p.seg = v[0];
     int n = v.size();
     for (int i = 1; i < n; ++i) {
         if(v[i] > p.prim) p.prim = v[i];
         if (v[i] < p.seg) p.seg = v[i];
     }
     return p;
}
 
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
pair<int,int> max_min2(const vector<int>& v) {
    pair <int,int> PAIR;
    parint p = max_min1(v);
    PAIR.first = p.prim;
    PAIR.second = p.seg;
    return PAIR;
}

 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
void max_min3(const vector<int>& v, int& x, int& y) {
    pair <int,int> PAIR1;
    PAIR1 = max_min2(v);
    x = PAIR1.first;
    y = PAIR1.second;
 }

/*
int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];                //Llegir el vector

    int x,y;
    max_min3(v,x,y);
    cout << x << " " << y << endl;
}
*/