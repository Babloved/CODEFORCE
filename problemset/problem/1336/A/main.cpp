#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Graph{
    int root = -1;
    int mass = 1;
    int rangeFromRoot = 0;
    vector<int> child;
    vector<int> connect;
    bool isEnd = false;
    bool isIndustrial = true;
};




void Tracing(int root, int child,int childMass,  vector<Graph> &city){
    city[root].mass = city[root].mass + childMass;
    city[root].child.push_back(child);
    auto search = find(city[root].connect.begin(),city[root].connect.end(),child);
    if (search != city[root].connect.end()){
        city[root].connect.erase(search);
        if (city[root].connect.size() == 1 and city[root].root !=0){
            city[root].root = city[root].connect[0];
            Tracing(city[root].root,root,city[root].mass,city);
        }
    }
}

void TracingRoot(int root,vector<Graph> &city,int &countResort){
    if (!city[root].isIndustrial){
        countResort++;
    }
    if (city[root].root >0){
        TracingRoot(city[root].root,city,countResort);
    }
};

void TracingRangeRoot(int i,vector<Graph> &city,int rangeFromRoot){
    if (!city[i].isEnd){
        for (auto child:city[i].child) {
            city[child].rangeFromRoot = rangeFromRoot;
            TracingRangeRoot(child, city,rangeFromRoot+1);
        }
    }

};





int  Solution(){
    int n,k;// n города k индустриальные города
    cin >> n >> k;
    vector <Graph> city (n+1);

    city[1].root= 0;
    for (int i = 0; i < n-1; ++i) {
        pair<int,int> road;
        cin >> road.first >> road.second;
        city[road.first].connect.push_back(road.second);
        city[road.second].connect.push_back(road.first);
    }

    for (int i = 1; i < n+1; ++i) {
        if (city[i].connect.size() == 1 and city[i].child.size()==0){
            city[i].isEnd = true;
            city[i].root = city[i].connect[0];
            city[i].mass = 1;
            Tracing(city[i].root,i,city[i].mass,city);
        }
    }
    TracingRangeRoot(1,city,1);//оцениваем удаленность города

    vector<tuple<int,int,int>> sortMassRangeCity;//first index second mass

    for (int i=0;i<n+1;++i) {
        if (city[i].root!=-1){
            sortMassRangeCity.emplace_back(city[i].mass,city[i].rangeFromRoot, i);
        }
    }

    auto comp = [](auto p1, auto p2) {
        if(get<0>(p1) < get<0>(p2)) return true;
        if(get<0>(p1) > get<0>(p2)) return false;
        return get<1>(p1) >= get<1>(p2);
    };

    std::sort(sortMassRangeCity.rbegin(), sortMassRangeCity.rend(),comp);

    for (int i = 0; i < n-k; ++i) {
        city[get<2>(sortMassRangeCity[i])].isIndustrial = false;
    }

    int countResortVisited =0;
    for (int i = n-k; i <n and sortMassRangeCity.size()>n-k; ++i) {
        TracingRoot(city[get<2>(sortMassRangeCity[i])].root, city, countResortVisited);
    }
    cout << countResortVisited;

    return 0;
}

int main(){
    Solution();
    return 0;
}