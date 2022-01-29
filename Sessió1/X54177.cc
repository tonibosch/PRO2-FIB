#include <iostream>
using namespace std;

int main() {
    int n, x,line = 1;
    cin >> n >> x;
    
    for (int i = 0; i < n; ++i) {
        int num, sum = 0;
        string s;
        cin >> num;
        while (num != x) {
            sum += num;
            cin >> num;
        }
        cout << "La suma de la secuencia " << line << " es " << sum << endl;
        getline(cin,s);
        ++line;
    }
}