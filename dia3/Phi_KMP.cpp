
#include <iostream>

using namespace std;

const int N = 1e6 + 5;
string s;
int phi[N];

// calcular phi function para todos prefixos de s
void calc_phi() {
    phi[0] = phi[1] = 0;
    
    for(int i = 2; i <= (int)s.size(); i++) {
        int x = phi[i-1];
        
        while(x != 0 and s[x] != s[i-1]) {
            x = phi[x];
        }
        
        if(s[x] == s[i-1])
            phi[i] = x+1;
        else
            phi[i] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    string p, t;  //p -> padrao
                  //t -> texto
    
    cin >> p >> t;
    s = p + "#" + t;
    
    calc_phi();
    
    // kmp: achar ocorrencias de p em t
    for(int i = p.size() + 2; i <= (int)s.size(); i++) {
        if(phi[i] == p.size())
            cout << i - p.size() - p.size() - 1 << " " << i-1-p.size()-1 << endl;
    }
    
    // ab#abcabaa
    
    return 0;
}
