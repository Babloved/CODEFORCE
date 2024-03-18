#include <iostream>


using namespace std;

int main(){
    int n,m, counter = 0;
    cin>>n>>m;

    while (m!=n){
        if(m>n){
            if(m%2==0){
                m/=2;
            }else{
                m++;
            }
        }else{
            n--;
        }
        counter++;
    }
    cout<<counter;
}