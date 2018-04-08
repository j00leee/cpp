#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // Fill in.
	static int adj[8][5] = {
		{-1},
		{0, -1},
		{0, 1, -1},
		{0, 2, -1},
		{1, 2, -1},
		{1, 2, 3, 4, -1},
		{2, 3, 5, -1},
		{4, 5, 6, -1}
	};
	
	
	for(int i = 0; i < c; i++){
		if(q[i] == q[c])
			return false;
	}
	

	for(int i = 0; adj[c][i] != -1; i++){
		if(abs(q[c] - q[adj[c][i]]) == 1)
			return false;
	}
	return true;
}

void print(int q[]) {
   // Fill in.
   static int numSolutions = 1;
   cout << "Solution #" << numSolutions++ << ": " << endl;
   cout << " " << q[1] << q[4] << " " << endl;
   cout << q[0] << q[2] << q[5] << q[7] << endl;
   cout << " " << q[3] << q[6] << " " << endl;
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] < 9; ++q[c]){
      if (ok(q, c))
         next(q, c+1);
	}
}



int main() {
   int q[8];
   next(q, 0);
   return 0;
}