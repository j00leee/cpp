#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int cost[NUM_ROWS][NUM_COLS] = {};
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
   for(int x = 0; x < NUM_ROWS; x++){
   		cost[x][0] = weight[x][0];
   		path[x][0] = to_string(x);
   }
   // For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.
   for(int i = 1; i < NUM_COLS; i++){
   		for(int j = 0; j < NUM_ROWS; j++){
   			int up = cost[(j+NUM_ROWS-1)%NUM_ROWS][i-1];
			  int down = cost[(j+1)%NUM_ROWS][i-1];
			  int left = cost[j%NUM_ROWS][i-1];
			  int minCost = min(min(up, left), down);
			
			if(minCost == up){
			  path[j][i] = path[(j + (NUM_ROWS - 1)) % NUM_ROWS][i - 1] + to_string(j);
			}
	
		  else if(minCost == left){
				path[j][i] = path[j][i - 1] + to_string(j);
			}

		  else{
		    path[j][i] =path[(j + 1) % NUM_ROWS][i - 1] + to_string(j);
			}
		  cost[j][i] = minCost + weight[j][i];
		}
   }

   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
   for(int x = 1; x < NUM_ROWS; x++){
		if(cost[x][NUM_COLS-1] < cost[0][NUM_COLS-1]){
			minRow = x;
			cost[0][NUM_COLS - 1] = cost[x][NUM_COLS-1];
		}
   }
   
   cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";
}

int main() {
   calculateCosts();

   return 0;
}