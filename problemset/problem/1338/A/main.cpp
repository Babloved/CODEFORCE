#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int x = 0, t = 0, n = 0, maxTime = -1;
    double temp = 0;
    cin >> t;
    vector<int> result(t);
    for (int j = 0; j < t; ++j) {
        cin >> n;
        maxTime = -1;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {

            cin >> a[i];
            b[i] = -1;
            if (i != 0) {
                while (a[i - 1] > a[i]) {
//                    temp = log(a[i-1]-a[i])/log(2);
                    b[i] = log(a[i - 1] - a[i]) / log(2);
                    b[i] > maxTime ? maxTime = b[i] : 0;
                    a[i] = a[i] + pow(2, b[i]);
                }
            } else {
                a[i] = a[i];
            }
        }
        result[j] = maxTime + 1;

    }
    for (auto el: result) {
        cout << el << endl;
    }
    return 0;
}