#include <iostream>
#include <algorithm>
using namespace std;

// Returns the difference between the largest element and the smallest element
int range(int a[], int size) {
   // Fill in.
   int smallest = a[0];
   int largest = a[0];
   for(int i = 0; i < size; i++){
      if(a[i] > largest){
         largest = a[i];
      }
      if(a[i] < smallest){
         smallest = a[i];
      }
   }
   return largest - smallest;
}

// Reverses the order of the elements
// Feel free to use the swap function (it's in the algorithm library so you don't have to write it yourself)
void reverse(int a[], int size) {
   // Fill in.
   int temp;
   for(int i = 0, j = size-1; i < size/2 ; i++, j--){
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
   }
}

// Sets all of the elements to 0
void zeroFill(int a[], int size) {
   // Fill in.
   for(int i = 0; i <= size; i++){
      a[i] = 0;
   }
}

int main () {
   int a[4] = {7, 2, 8, 3};
   int b[5] = {3, 4, 5, 6, 7};
   
   cout << "The range of array a is " << range(a, 4) << endl;
   cout << "The range of array b is " << range(b, 5) << endl;
   
   reverse(a, 4);
   reverse(b, 5);
   cout << "Array a reversed: ";
   for (int i = 0; i < 4; ++i)
      cout << a[i] << " ";
   cout << endl;
   cout << "Array b reversed: ";
   for (int i = 0; i < 5; ++i)
      cout << b[i] << " ";
   cout << endl;
   
   zeroFill(b, 5);
   cout << "Array b (after calling zeroFill): ";
   for (int i = 0; i < 5; ++i)
      cout << b[i] << " ";
   
   return 0;
}