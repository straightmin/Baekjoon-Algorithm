#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for(int i = 0; i < n; i++){
		v[i].resize(i+1);
		for(int j = 0; j <= i; j++){
			cin >> v[i][j];
			if(i == 0) continue;
			
			if(j == 0){
				v[i][j] += v[i-1][j];
				continue;
			}
			if(j == i){
				v[i][j] += v[i-1][j-1];
				continue;
			}
			
			v[i][j] += max(v[i-1][j], v[i-1][j-1]);
		}
	}
	
	sort(v[n-1].begin(), v[n-1].end());
	cout << v[n-1][n-1];
	
	return 0;
}

