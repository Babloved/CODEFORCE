#include <iostream>
#define ARRSIZE 101
//14214342321233523215434634243324
using namespace std;

int main(){
    char number[ARRSIZE]{0};
    int n = 0;
    for (; n < ARRSIZE; ++n) {
        cin.get(number[n]);
        if (number[n]==8){
            break;
        }
        else if (number[n] == '\n'){
            break;
        }
    }





    return 0;
}