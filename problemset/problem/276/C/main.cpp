#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n = 0, q=0,max = 0;
    long long result=0;
    cin>>n>>q;
    vector<long long>a(n);
    vector<long long>b(n+1);
    vector<long long>mass(n+2);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());

    int first=0,second=0;
    for (int i = 0; i < q; ++i) {
        cin>>first>>second;
        mass[first]++;
        mass[second+1]--;
    }
    for (int i = 0; i < n; ++i) {
        b[i+1]=b[i]+mass[i+1];

    }


    sort(b.rbegin(),b.rend());
    for (int i = 0; i < n; ++i) {
        result += b[i]*a[i];
    }

    cout<< result;
    return 0;
}