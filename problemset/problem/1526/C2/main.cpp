#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int solution(){
    long long n = 0,health =0,drank =0;
    priority_queue<long long>negative;

    cin>> n;
    for (int i = 0; i < n; ++i) {
        long long temp =0;
        cin>>temp;
        if ( temp >= 0){
            health += temp;
            drank++;
            continue;
        }
        temp = abs(temp);//убираем знак
        if(temp <= health){
            negative.push(abs(temp));
            health -= temp;
            drank++;
        }
        else{
            if(!negative.empty()){
                int first = negative.top();
                if (first > temp){
                    negative.pop();
                    negative.push(temp);
                    health += first-temp;
                }
            }
        }

    }

    cout << drank;
    return 0;
}

int main(){
    solution();

    return 0;
}