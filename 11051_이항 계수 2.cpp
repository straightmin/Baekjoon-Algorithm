#include <iostream>

using namespace std;

int DP[1001][1001] = {};

int top_down(int n, int k){
    if(n == k){
        return DP[n][k] = 1;
    }
    if(k <= 1){
        return DP[n][k] = n;
    }
    if(DP[n][k] != 0){
        return DP[n][k];
    }
    
    DP[n-1][k-1] = top_down(n-1, k-1) % 10007;
    DP[n-1][k] = top_down(n-1, k) % 10007;
    return DP[n][k] = (DP[n-1][k-1] + DP[n-1][k]) % 10007;
}

int main(){
    int n, k;
    cin >> n >> k;
    
    cout << top_down(n, k);
    return 0;
}

