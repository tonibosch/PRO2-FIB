#include<iostream>
#include <map>
#include <string>
using namespace std;

int main () {
    map<string, int> p;
    char c;
    string s;
    while (cin >> c >> s) {
        map<string, int>::const_iterator it = p.find(s);
        if(c == 'a') p[s]++;
        else if (c == 'f') cout << p[s] << endl;
    
        else if(c =='e') {
             if(it != p.end() and p[s] != 0) --p[s];
        }
    }
}