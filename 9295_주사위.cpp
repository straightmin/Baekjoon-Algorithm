#include <iostream>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	int a, b;
	for(int i = 1; i <= tc; i++){
		cin >> a >> b;
		cout << "Case " << i << ": " << a+b << '\n';
	}
	
	return 0;
}

