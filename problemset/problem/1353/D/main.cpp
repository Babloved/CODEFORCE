#include <iostream>
#include "bits.h"
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <tuple>

using namespace std;
class CoordData{
public:
    int range,coordinate;

};

class compCoordData {
public:
    bool operator()(const CoordData &lhs,const CoordData &rhs)
    {
        if (lhs.range!=rhs.range ) {
            return lhs.range<rhs.range; //whatever
        }else{
            return lhs.coordinate>rhs.coordinate;
        }
    }
};


int main(){

    int t,a,coordinate,range,midRange;
    cin >> t;
    priority_queue<CoordData,vector<CoordData>, compCoordData> dMidRange;

    vector<vector<int>> vResult;

    for (int i = 0; i < t; ++i) {
        cin>>a;
        dMidRange.push({a,0});
        vector<int>vec(a);
        for (int j = 0; !dMidRange.empty(); ++j) {

            coordinate = dMidRange.top().coordinate;
            range = dMidRange.top().range;
            dMidRange.pop();

            if (range > 1) {
                if (range % 2 == 0) {//чет или нечет
                    midRange = range / 2;
                } else {
                    midRange = ceil(double(range) / 2);
                }

                if (midRange - 1 > 0) {
                    dMidRange.push({midRange - 1, coordinate});
                }
                if (coordinate + range - midRange > 0) {
                    dMidRange.push({range - midRange, coordinate + midRange});
                }

                vec[coordinate+midRange-1] = j+1;
            } else {
                vec[coordinate] = j+1;
            }

        }
        vResult.push_back(vec);
    }
    for (auto upEl:vResult) {
        for (auto downEl:upEl) {
            cout << downEl << " ";
        }
        cout << endl;
    }


    return 0;
}