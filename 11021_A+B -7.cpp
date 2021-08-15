#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	cin >> n;
	for(int i = 1; i <= n; i++){
	    cin >> a >> b;
	    a += b;
	    cout << "Case #" << i << ": " << a << '\n';
    }
	
	return 0;
}

