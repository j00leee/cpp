#include <iostream>
using namespace std;

bool ok(int q[], int c){
	static int mp[3][3] = {{0, 2, 1}, {0, 2, 1}, {1, 2, 0}};
	static int wp[3][3] = {{2, 1, 0}, {0, 1, 2}, {2, 0, 1}};
	
	for(int i = 0; i < c; i++){
		if(q[c] == q[i]){
			return false;
		}
	}
	for(int i = 0; i < c; i++){
		if((mp[i][q[c]] < mp[i][q[i]]) && (wp[q[c]][i] < wp[q[c]][c])){
			return false;
		}
		if((mp[c][q[i]] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i])){
			return false;
		}
	}
	return true;
}

void print(int q[]){
	static int solution = 1;
	cout << "Solution #" << solution++ << ":\nMan\tWoman\n";
	for(int i = 0; i < 3; i++){
		cout << i << "\t" << q[i] << "\n";
	}
	cout << endl;
}

void next(int q[], int c){
	if(c == 3){
		print(q);
	}
	else for(q[c] = 0; q[c] < 3; q[c]++){
		if(ok(q, c)){
			next(q, c+1);
		}
	}
}


int main(){
	int q[3];
	next(q, 0);
	return 0;
}