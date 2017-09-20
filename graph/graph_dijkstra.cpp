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
using namespace std;
//ダイクストラ法
int cost[10001][10001]; //cost　存在しない場合INF
int d[10001]; //頂点sからの最短距離
bool used[10001]; //すでに使われたかのフラグ
int V; //頂点数

//始点sから各頂点への最短距離を求める
void dijkstra(int s){
    //配列の代入はfilln
    fill(used, used + V, false);
    d[s] = 0;

    while(1){
        int v = -1;
        //まだ使われてない頂点のうち距離が最小のものを探す
        for (int u = 0; u < V; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if ( v == -1 ) break;

        used[v] = true;

        for(int u = 0; u < V; u++){
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);


    return 0;
}
