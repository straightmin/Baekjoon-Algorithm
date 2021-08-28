#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int a, b;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a+b << '\n';
	}
}

