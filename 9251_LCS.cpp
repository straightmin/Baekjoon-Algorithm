#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;
    
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int DP[n+1][m+1] = {};
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            } else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    
    cout << DP[n][m];
    return 0;
}

