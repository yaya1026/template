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
//蟻本p94の問題
//dfsを用いた彩色
vector<int> G[100001];
int color[100001];//頂点iの色の番号

bool dfs(int v, int c){
    //頂点vをcで塗る
    color[v] = c;

    for(int i = 0; i < G[v].size(); i++){
        //隣接している頂点が同じ色ならfalse
        if(color[G[v][i]] == c) return false;
        //隣接している頂点がまだ塗られていないなら-cで塗る
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    //全ての頂点を塗れたらtrue
    return true;

}

void solve(int V){
    for(int i = 0; i < V; i++){
        if(color[i] == 0){
            //まだ頂点iが塗られていなければ1で塗る
            if(!dfs(i, 1)){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;//V:頂点 E:辺

    cin >> V >> E;
    
    REP(i, E){
        //sからtへの辺を張る
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    solve(V);

    return 0;
}

