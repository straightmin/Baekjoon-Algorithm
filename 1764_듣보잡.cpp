#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string input;
	map<string, string> name;
	vector<string> v;
	
	while(n--){
		cin >> input;
		name.insert({input, input});
	}
	while(m--){
		cin >> input;
		if(name.find(input) != name.end()){
			v.push_back(input);
		}
	}
	
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(auto i:v) cout << i << '\n';
}

