#include <iostream>
using namespace std;

// Swaps the parameters if the 1st parameter is larger than the 2nd parameter
void sort(int &a, int &b) { // Fill in the parameters (don't forget to pass by reference)
   // Fill in.
   int temp = a;
   if(a > b){
      a = b;
      b = temp;
      return;
   }
}

// Returns the result of the removing the 2nd digit
int remove2nd(int n) {
   // Fill in.
   if(n < 100){
        return n / 10;
    }
    else{
        return (10 * remove2nd(n / 10)) + (n % 10);
    }
}

// Returns true if every digit is >= the digit to its left, otherwise returns false
bool ascending(int n) {
   // Fill in.
   while(n < 100){
      if((n % 10) >= (n / 10)) 
         return true;
   }
   if(ascending(n / 10) && ((n / 10) % 10) <= (n % 10)){
      return true;
   }
   else{
      return false;
   }
}

int main () {
   int x = 6, y = 3;
   sort(x, y);
   cout << x << " " << y << endl;
   sort(x, y);
   cout << x << " " << y << endl;
   cout << remove2nd(3456) << endl;
   if (ascending(3345))
      cout << "3345 is ascending" << endl;
   else
      cout << "3345 is not ascending" << endl;
   if (ascending(3545))
      cout << "3545 is ascending" << endl;
   else
      cout << "3545 is not ascending" << endl;

   return 0;
}