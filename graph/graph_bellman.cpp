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
#define INF 1000000001;
using namespace std;
//ベルマンフォード法(単一始点最短経路問題)
//始点を固定した時に,他のすべての頂点との間の最短路を求める問題
struct edge{int from, to, cost;};//頂点from から　頂点to へのcostの辺
edge es[100001];
//int d[100001]; //最短距離
int V, E;//Vは頂点数, Eは辺数

//s番目の頂点から各頂点への最短距離を求める
void shorttest_path(int s){
    int d[100001];
    for(int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;

    while(1){
        bool update = false;
        for(int i = 0; i < E; i++){
            edge e = es[i];

            if (d[e.from] != INF && d[e.to] > (d[e.from] + e.cost)){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
            
        }
        if(!update) break;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;

    REP(i, E){
        cin >> es[i].from >> es[i].to >> es[i].cost;
    }

    //shorttest_path();

    return 0;
}
