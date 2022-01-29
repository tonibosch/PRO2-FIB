#include <stack>
#include <iostream>
using namespace std;

int main (){
    int n,x;
    cin >> n;
    
    stack<int> p;
    bool palindrom = true;
    for (int i = 0; i < n/2; ++i) {
        cin >> x;
        p.push(x);
    }
    
    if(n%2 == 1) cin >> x;
    
    for (int i = 0; i < n/2 and palindrom; ++i) {
       cin >> x;
       if(p.top() != x) palindrom = false;
       p.pop();
    }
    
    if(palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;
}