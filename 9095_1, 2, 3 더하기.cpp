#include <iostream>

using namespace std;

int main(){
    int tc, n;
    cin >> tc;
    int DP[11] = {};
    DP[1] = 1, DP[2] = 2, DP[3] = 4;
    
    while(tc--){
        cin >> n;
        for(int i = 4; i <= n; i++){
            if(DP[i] == 0){
                DP[i] = DP[i-1]+DP[i-2]+DP[i-3];
            }
        }
        cout << DP[n] << '\n';
    }
    return 0;
}

