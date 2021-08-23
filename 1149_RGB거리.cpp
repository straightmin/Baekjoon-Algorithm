#include <iostream>

using namespace std;

int DP[1000][3];

int main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> DP[i][0] >> DP[i][1] >> DP[i][2];
		if(i == 0) continue;
		for(int j = 0; j < 3; j++){
			int temp = 1e9+1;
			for(int k = 0; k < 3; k++){
				if(j == k) continue;
				temp = min(temp, DP[i-1][k]);
			}
			DP[i][j] += temp;
		}
	}
	
	int ans = min(min(DP[n-1][0], DP[n-1][1]), DP[n-1][2]);
	cout << ans;
}

