#include <iostream>
using namespace std;

int main(){
    int n=0,temp=0, chet{0}, nechet{0},lastChet{0},lastNechet{0};
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>temp;
        if (temp % 2 == 0){
            lastChet=i;
            chet++;
        }else{
            lastNechet=i;
            nechet++;
        }
    }
    if (chet<nechet){
        cout<<lastChet+1;
    }else{
        cout<<lastNechet+1;
    }
}
