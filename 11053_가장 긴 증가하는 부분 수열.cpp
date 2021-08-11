#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int DP[n] = {};
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    DP[0] = 1;
    int maximum = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                DP[i] = max(DP[i], DP[j]);
            }
        }
        DP[i]++;
        maximum = max(DP[i], maximum);
    }
    
    cout << maximum;
    
    return 0;
}

