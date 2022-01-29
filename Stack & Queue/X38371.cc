#include <iostream>
#include <queue>
using namespace std;

void recalcular_max_min(queue<int>& q, int& max,int& min){
    bool first = true;
    for(int i = 0; i < q.size(); ++i){
        if(first){
            max = q.front();
            min = q.front();
            first = false;
        }
        else {
            if(q.front() > max) max = q.front();
            else if(q.front() < min) min = q.front();
        }
        q.push(q.front());
        q.pop();
    }
}


int main (){
    int n;
    queue<int> q;
    bool first = true;
    int max,min;
    double mitj = 0;
    
    while(cin >> n and n >= -1001 and n <= 1000) {
        if(n != -1001) {
            if(first){
                max = n;
                min = n;
                mitj = n;
                first = false;
            }
            else {                          //n != -1001 i no es primer nombre
                if(n > max) max = n;
                else if(n < min) min = n;
                mitj += n;
            }
            q.push(n);
        }
        else if (not q.empty()){
                int n_vell = q.front();
                q.pop();
                mitj -= n_vell;
                if(n_vell == max or n_vell == min) recalcular_max_min(q,max,min);
                
        }
        if(not q.empty()) cout << "min " << min << "; max " << max << "; media " << mitj/q.size() << endl;
        else {
            first = true;
            cout << 0 << endl;
        }
    }
}