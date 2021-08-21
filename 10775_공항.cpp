#include <iostream>

using namespace std;

int g, p;
int gate[101010];

int find_gate(int g){
	if(gate[g] == g) return g;
	
	return gate[g] = find_gate(gate[g]);
}

bool dock(int g){
	g = find_gate(g);
	if(g == 0) return false;
	
	gate[g]--;
	return true;
}

int main(){
	cin >> g >> p;
	
	for(int i = 1; i <= g; i++){
		gate[i] = i;
	}
	
	int arrival[p];
	for(int i = 0; i < p; i++){
		cin >> arrival[i];
	}
	
	int airplane = 0;
	for(int i = 0; i < p; i++){
		if(!dock(arrival[i])) break;
		airplane++;
	}
	
	cout << airplane;
	
	return 0;
}

