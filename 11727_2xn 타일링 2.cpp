#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int DP[n];
    
    DP[0] = 1;
    DP[1] = 3;
    for(int i = 2; i < n; i++){
        DP[i] = (DP[i-1] + 2*DP[i-2]) % 10007;
    }
    
    cout << DP[n-1];
    return 0;
}

