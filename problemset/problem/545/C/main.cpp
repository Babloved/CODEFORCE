#include <iostream>
#include <bits.h>
#include <vector>
using namespace std;

struct Tree{
    long long x=0;
    long long h=0;
    short drop=0;
};

int main(){

    int n = 0,passDistance = 0,d=0;
    cin>>n;
    vector<Tree> vTrees(n);

    for (int i = 0; i < n; ++i) {
        cin>>vTrees[i].x>>vTrees[i].h;
    }

    for (int i = 0,j=n-1; i < n ; ++i) {


        if (i == 0) {
            vTrees[i].drop = -1;
        }
        else if (i==n-1){
            vTrees[i].drop = 1;
        }
        else {// обработка с начала
            if (vTrees[i-1].drop <=0 and vTrees[i].x-vTrees[i-1].x>vTrees[i].h){//прошлое дерево упало на лево
                vTrees[i].drop = -1;
            }
            else if (vTrees[i-1].drop > 0 and vTrees[i].x-vTrees[i-1].x-vTrees[i-1].h>vTrees[i].h){ //прошлое дерево упало на право
                vTrees[i].drop = -1;
            }
            else if (i+1<n and vTrees[i+1].x-vTrees[i].x>vTrees[i].h){
                vTrees[i].drop = 1;
            }
            else{
                vTrees[i].drop = 0;
            }
        }

    }
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        if (vTrees[i].drop !=0){
            result++;
        }
    }
    cout << result;
    return 0;
}

/*
4
1 3
2 4
8 1
12 5
________________
4
10 4
15 1
19 3
20 1
wrong answer expected '4'



 * */