#include <iostream>
#include <stack>

using namespace std;

int k, num, ans = 0;
stack<int> s;

int main(){
	cin >> k;
	
	while(k--){
		cin >> num;
		
		if(num != 0)
			s.push(num);
		else
			s.pop();
	}
	
	while(!s.empty()){
		ans += s.top();
		s.pop();
	}
	
	cout << ans;
	
	return 0;
}

