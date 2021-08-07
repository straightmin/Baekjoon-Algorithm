/* Kanpsack 문제 2차원 배열 풀이 */

#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int **DP, *w, *v;
    
    w = new int[n];
    v = new int[n];
    DP = new int *[n+1];
    for(int i = 0; i <= n; i++){
        DP[i] = new int[k+1];
    }
    
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(i == 0 || j == 0){
                DP[i][j] = 0;
                continue;
            }
            
            if(w[i-1] > j){
                DP[i][j] = DP[i-1][j];
            } else{
                DP[i][j] = max(DP[i-1][j-w[i-1]]+v[i-1], DP[i-1][j]);
            }
        }
    }
    
    cout << DP[n][k];
     
    return 0;
}

