#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

template<typename K, typename V>
std::multimap<V,K> reverseMap(std::map<K,V> const &map) {
std::multimap<V,K> rMap;
for (auto const &[k, v] : map) {
rMap.emplace(v,k);
}
return rMap;
}

int main() {
    unsigned int n = 0, temp = 0,temp2=0;
    cin >> n;
    map<int,int> mp;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        mp[temp] += temp;
    }
    multimap<int,int>flipMap = reverseMap(mp);  //ключ на второй позиции
    unordered_multimap<int,int>flipHashMap;


    for (auto pair = flipMap.rbegin(); pair != flipMap.rend(); ++pair) {  //ключ на второй позиции
        flipHashMap.insert(make_pair(pair->second,pair->first));
    }

    int results  = 0;
    int last = 0;
//    for (auto pair = flipMap.rbegin(); pair != flipMap.rend(); ++pair) {
//        temp = flipHashMap[pair->second-1]+flipHashMap[pair->second+1];
//        temp2 = flipHashMap[pair->second];
//        if (flipHashMap[pair->second] != 0 && temp2 > temp  ){
//            flipHashMap[pair->second+1] = 0;
//            flipHashMap[pair->second-1] = 0;
//            results += flipHashMap[pair->second];
//        }
//        else if(flipHashMap[pair->second] != 0 ){
//            flipHashMap[pair->second+2] = 0;
//            flipHashMap[pair->second-2] = 0;
//            flipHashMap[pair->second] = 0;
//        }
//
//    }

//sdasdasdsa


    cout << results;
    return 0;
}