#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
void solution(){
    long long n,m,k,needVisit,x,y;
    n= m= k= needVisit=0;
    cin>>n>>m>>k;

    vector<vector<char>>table(n,vector<char>(m));
    vector<vector<long long>>visited(n, vector<long long>(m, 0));
    queue<pair<long long,long long>> stack;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
            if (table[i][j]=='.'){
                table[i][j] = 'X';
                if (stack.empty()){
                    stack.emplace(i,j);
                }
                needVisit++;
            }
        }
    }
    needVisit -= k;
    while (needVisit > 0 and !stack.empty()){
        x = stack.front().first;
        y = stack.front().second;
        stack.pop();
        if  (x < 0 || x>=n || y < 0 || y>=m || visited[x][y] > 0 || table[x][y] == '#' ){
            continue;
        }
        needVisit--;
        visited[x][y]++;
        table[x][y] = '.';


        stack.emplace(x-1,y);
        stack.emplace(x+1,y);
        stack.emplace(x,y+1);
        stack.emplace(x,y-1);
    }
    for (int i = needVisit = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << table[i][j];
        }
        cout<< endl;
    }

}


int main(){
    solution();

    return 0;
}










