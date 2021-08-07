/* Kanpsack ���� 1���� �迭 Ǯ�� */

#include <iostream>

using namespace std;

int main(){
    int n, k, w, v;
    cin >> n >> k;
    int DP[k+1] = {};
    
    while(n--){
        cin >> w >> v;
        for(int i = k; i >= w; i--){
            if(DP[i-w]+v > DP[i]){
                DP[i] = DP[i-w]+v;
            }
        }
    }
    
    cout << DP[k];
    return 0;
}

