#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, n) for (int i = n; i >= 0; i--)
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <vector>
#define ll long long
#define INF 1000000000
using namespace std;
//ワーシャルフロイド
//グラフの全点間の最短距離を求める
//初期化はVを入力で受け取った直後
//O(n^3)
//これはAtcoder Beginner Contest 012のD問題

int d[301][301];//i,j間の最短距離
int E, V;//辺,頂点

void init(){
    REP(i, V){
        REP(j, V){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
}

void make(){
    REP(i, E){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        d[u][v] = c;
        d[v][u] = c;
    }
}

void wd(){
    REP(k, V){
        REP(i, V){
            REP(j, V){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    cin >> V >> E;

    init();
    make();
    wd();

    vector<int> bus;
    REP(i, V){
        int cost = d[i][0];
        REP(j, V){
            cost = max(cost, d[i][j]);
        }
        bus.push_back(cost);
    }

    sort(bus.begin(), bus.end());

    cout << bus.front() << endl;

}
