#include <iostream>
#include <queue>

using namespace std;

long long a, b;

int bfs(){
	queue<pair<long long, long long> > q;
	q.push({a, 1});
	
	while(!q.empty()){
		pair<long long, long long> curr = q.front();
		q.pop();
		
		if(b == curr.first*10+1) return curr.second+1;
		if(curr.first*10+1 <= b)
			q.push({curr.first*10+1, curr.second+1});
		if(b == curr.first*2) return curr.second+1;
		if(curr.first*2 <= b)
			q.push({curr.first*2, curr.second+1});
	}
	
	return -1;
}

int main(){
	cin >> a >> b;
	
	cout << bfs();
}

