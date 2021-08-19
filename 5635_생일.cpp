#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	pair<int, pair<int, pair<int, string> > > p[n];
	
	for(auto &iter : p){
		cin >> iter.second.second.second >> iter.second.second.first
			>> iter.second.first >> iter.first;
	}
	
	sort(p, p+n);
	
	cout << p[n-1].second.second.second << '\n';
	cout << p[0].second.second.second << '\n';
	
	return 0;
}

