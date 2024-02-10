#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;
int main(){
    int n=0,l=0,temp=0,last =0;
    double r = -1;
    set<int> lightPosition;

    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        lightPosition.insert(temp);
    }
    for (int el:lightPosition) {
        if (r == -1){
            r = el;
        }
        else if (r < double(el-last)/2){
            r = double(el-last)/2;
        }
        if((el == *lightPosition.rbegin()) && (r <( l - *lightPosition.rbegin()))){
            r = l - *lightPosition.rbegin();
        }
        last = el;
    }
    cout <<std::setprecision(9)<<r;
    return 0;
}