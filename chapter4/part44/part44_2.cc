/*
ID: Zhi Li
PROG: milk6
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int N, M;
struct edge { int to, cap, rev; };
vector<edge> G[35];
int level[35], iter[35];
const int INF = 1000000000;
void add_edge(int from, int to, int cap) {
  G[from].push_back((edge) { to, cap, G[to].size() } );
  G[to].push_back((edge) { from, 0, G[from].size() - 1 } );
}
void bfs(int s) {
  memset(level, -1, sizeof level);
  queue<int> q;
  level[s] = 0;
  q.push(s);
  while(!q.empty()) {
    int v = q.front(); q.pop();
    for(int i = 0; i < (int) G[v].size(); i++) {
      edge &e = G[v][i];
      if(e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        q.push(e.to);
      }
    }
  }
}
int dfs(int v, int t, int f) {
  if(v == t) return f;
  for(int &i = iter[v]; i < (int) G[v].size(); i++) {
    edge &e = G[v][i];
    if(e.cap > 0 && level[e.to] > level[v]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int flow = 0;
  for(;;) {
    bfs(s);
    if(level[t] < 0) return flow;
    int f;
    memset(iter, 0, sizeof iter);
    while((f = dfs(s, t, INF)) > 0) flow += f;
  }
}
struct route { int from,  to, cap, id; };
route r[1010], tmp[1010];
bool comp(route a, route b) {
  if(a.cap > b.cap || (a.cap == b.cap && a.id < b.id)) return 1;
  else return 0;
}

void init(void) {
  for(int i = 0; i < M; i++) tmp[i] = r[i];
}

int main(void) {
  ifstream fin ("milk6.in");
  ofstream fout ("milk6.out");
  fin >> N >> M;
  int from, to, cap;
  for(int i = 0; i < M; i++) {
    fin >> from >> to >> cap;
    r[i].from = from; r[i].to = to; r[i].cap = cap; r[i].id = i + 1;
    add_edge(from, to, cap);
  }
  sort(r, r + M, comp);

  int total_flow = max_flow(1, N);
  fout << total_flow;
  vector<int> res;

  for(int i = 0; i < M; i++) {
    int t = r[i].cap;
    r[i].cap = 0;
    for(int m = 1; m <= N; m++) G[m].clear();
    for(int j = 0; j < M; j++) add_edge(r[j].from, r[j].to, r[j].cap);
    int f = max_flow(1, N);
    if(total_flow - f == t) {
      total_flow = f;
      res.push_back(r[i].id);
      if(total_flow == 0) break;
    }
    else r[i].cap = t;
  }

  fout << " " << res.size() << endl;
  if(res.size() > 0) sort(res.begin(), res.end());
  for(int i = 0; i < (int) res.size(); i++) fout << res[i] << endl;


  return 0;
}
