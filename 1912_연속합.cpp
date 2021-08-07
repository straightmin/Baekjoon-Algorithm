#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int DP[n] = {};
    
    for(auto &i : DP) cin >> i;
    
    int m = DP[0];
    for(int i = 1; i < n; i++){
        DP[i] = max(DP[i-1]+DP[i], DP[i]);
        m = max(m, DP[i]);
    }
    
    cout << m;
    
    return 0;
}

