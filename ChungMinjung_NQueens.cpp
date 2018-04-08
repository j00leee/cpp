#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // Reuse the ok function from your 1D 8 queens program.
   for(int i = 0; i < c ; i++){
    	if(q[c]==q[i] || (c-i)==abs(q[c]-q[i]) )
        	return false;
   }
   return true;
}

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
   // Dynamically declare an array of size n and initialize the first element to 0.
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
   // Delete the array.
   // Return the number of solutions.
   int* q = new (nothrow) int[n]();
   q[0] = 0;
   int c = 0, solutions = 0;
   while(c >= 0){
		if(c == n - 1){
   			solutions++;
   			c--;
		}
	   else{
			q[++c] = -1;
			
	   }
	   while(c >= 0){
			q[c]++;
			if(q[c] == n){
				c--;
			}
			else if(ok(q,c)){
				break;
			}
	   }
   } 
   delete[] q;
   return solutions;
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}