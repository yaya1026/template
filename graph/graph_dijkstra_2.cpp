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
#define INF 100000001
using namespace std;
struct edge{int to, cost;};
typedef pair<int, int> P;//first:cost second:vertex

int V;
vector<edge> G[100001];
int d[100001];

void dijkstra(int s){
    //greater<P>を指定することでfirstが小さい順に取り出せる,指定しないと大きい順に取り出す
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second;//secondは頂点
        if(d[v] < p.first) continue;
        REP(i,G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);


    return 0;
}
