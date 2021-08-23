#include <iostream>
#define ll long long

using namespace std;

ll DP[101];

ll tri(int n){
	if(DP[n] != 0) return DP[n];
	
	return DP[n] = tri(n-1) + tri(n-5);
}

int main(){
	int tc;
	cin >> tc;
	
	DP[1] = DP[2] = DP[3] = 1;
	DP[4] = DP[5] = 2;
	
	while(tc--){
		int n;
		cin >> n;
		cout << tri(n) << '\n';
	}
	
	return 0;
}

