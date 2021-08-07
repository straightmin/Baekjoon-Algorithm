#include <iostream>

using namespace std;

int main(){
	int n, m, v, c, k;
	cin >> n >> m;
	int DP[m+1] = {};
	
	while(n--){
	    cin >> v >> c >> k;
		for(int i = 1; k > 0; i <<= 1){
			const int ix = min(i, k);
			v *= ix;
			c *= ix;
			for(int j = m; j >= v; j--){
				if(DP[j-v]+c > DP[j]){
					DP[j] = DP[j-v]+c;
				}
			}
			k -= ix;
		}
	}
	
	cout << DP[m];
	return 0;
}

