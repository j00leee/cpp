#include <iostream>
using namespace std;

int main(){
    for(int x = 1; x <= 100; x++){
        int y = x*x;
        if((((y % 10) % 2) != 0) && ((((y / 10) % 10)) % 2) != 0){
            cout << y;
            return 0;
        }
    }
    cout << "There is no perfect square.";
    return 0;
}
