/*
ID: Zhi Li
PROG: ditch
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
const int inf = 987654321, MAX_V = 210;
struct edge { int to, cap, rev; };
vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap) {
  G[from].push_back((edge) { to, cap, G[to].size() });
  G[to].push_back((edge) { from, 0, G[from].size() - 1 });
}

int dfs(int v, int t, int f) {
  if(v == t) return f;
  used[v] = 1;
  for(int i = 0; i < (int) G[v].size(); i++) {
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0) {
      used[e.to] = 1;
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

int main(void) {
  ifstream fin ("ditch.in");
  ofstream fout ("ditch.out");
  fin >> N >> M;
  int from, to, cap;
  for(int i = 0; i < N; i++) {
    fin >> from >> to >> cap;
    add_edge(from, to, cap);
  }
  int f = 0;
  for(;;) {
    memset(used, 0, sizeof used);
    int d = dfs(1, M, inf);
    if(d == 0) break;
    f += d;
  }
  fout << f << endl;
  return 0;
}
