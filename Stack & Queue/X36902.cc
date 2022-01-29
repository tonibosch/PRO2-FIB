#include <stack>
#include <iostream>
using namespace std;

int main() {
    char c;
    stack<int> p;
    bool correcte = true;
    bool first = true;
    
    while (correcte and cin >> c and c != '.') {
        if(not first) {
            if((p.top() == '(' and c == ')') or (p.top() == '[' and c == ']')) {
                p.pop();
                if(p.empty()) first = true;
            }
            else if((p.top() == '(' and c == ']') or (p.top() == '[' and c == ')')) correcte = false;
            else p.push(c);
        }
        else {
            first = false;
            p.push(c);
        }
    }
    if(p.empty() and correcte) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}