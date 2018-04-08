#include <iostream>
using namespace std;

int main() {
   // Initialize the board to 0
  int q[8][8] = {};

   // Start in the 1st row, 1st column, and place a queen there
   int r = 0, c = 0;
   q[r][c] = 1;


nextCol:
   // Move to the next column
  c++;
  if (c == 8)
    goto print;

   // Move to one before the first row
  r = -1;

nextRow:
   // Move to the next row
   r++;

   if (r == 8)
      goto backtrack;

   // If there is a queen in the same row (to the left), goto nextRow
   for(int i = 0; i < c; i++){
      if (q[r][i] == 1)
         goto nextRow;
   }
   // If there is a queen in the upper-left diagonal, goto nextRow
   for (int i = 1; (r-i >= 0 && c-i >= 0); i++){ // End the loop when you are above or left of the chessboard
      if (q[r - i][c - i] == 1)
         goto nextRow;
   }
   // If there is a queen in the lower-left diagonal, goto nextRow
   for (int i = 1; (r+i < 8 && c-i >= 0); i++){ // End the loop when you are below or left of the chessboard
      if (q[r + i][c - i] == 1)
         goto nextRow;
   }

   // Place a queen in the current square (2D version only)
   q[r][c] = 1;
   goto nextCol;

backtrack:
   // Move to the previous column
    c--;
   if (c == -1)
      return 0;
      
   // Find the square in the column with a queen in it and set r to the row number of that square
   r = 0;
   while(q[r][c] != 1)
        r++;
   // Remove the queen from the current square
    q[r][c] = 0;
   goto nextRow;

print:
   static int numSolutions = 1;
   cout << "Solution #" << numSolutions++ << ":\n";
   // Use a nested loop to print the chessboard
   for(int i = 0; i < 8; i++){
       for(int j = 0; j < 8; j++){
           cout << q[i][j];
       }
       cout << endl;
   }
   cout << endl;
   goto backtrack;
}