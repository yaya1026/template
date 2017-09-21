#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, a, b) for (int i = a; i < (b); ++i)
#deine FOR(i, n) for (int i = n; i >= 0; --i)
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
#define INF (1LL << 50)
using namespace std;
struct Edge{int from, to, cost;};
//これはABC61のD

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;

    vector<Edge> edges;

    REP(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        Edge e1 = {a,b,c};
        edges.push_back(e1);
    }
    vector<ll> d(N, -INF);
    d[0] = 0;
    REP(i,N-1){
        //&をつけておけば値の書き換えもできる
        for(Edge& edge : edges){
            ll score = d[edge.from] + edge.cost;
            if(score > d[edge.to]){
                d[edge.to] = score;
            }
        }
    }

    ll ans = d[N-1];

    REP(i,N-1){
        for(Edge& edge : edges){
            ll score = d[edge.from] + edge.cost;
            if(score > d[edge.to]){
                d[edge.to] = score;
            }
        }
    }

    if(ans != d[N-1]) cout << "inf" << endl;
    else cout << ans << endl;

    return 0;

}