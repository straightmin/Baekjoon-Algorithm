#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int stairs[n];
    int DP[n];
    
    for(int i = 0; i < n; i++){
        cin >> stairs[i];
    }
    
    DP[0] = stairs[0];
    if(n == 1){ cout << DP[0]; return 0; }
    DP[1] = stairs[0] + stairs[1];
    if(n == 2){ cout << DP[1]; return 0; }
    DP[2] = stairs[2] + max(stairs[0], stairs[1]);
    if(n == 3){ cout << DP[2]; return 0; }
    
    for(int i = 3; i < n; i++){
        DP[i] = stairs[i] + max(DP[i-2], DP[i-3]+stairs[i-1]);
    }
    
    cout << DP[n-1];
    
    return 0;
}

