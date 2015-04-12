/*
ID: Zhi Li
PROG: stall4
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
struct edge {int to, cap, rev; };
vector<edge> G[450];
bool used[450];
const int inf = 2000000000;

void add_edge(int from, int to, int cap = 1) {
  G[from].push_back((edge) {to, cap, G[to].size() });
  G[to].push_back((edge) {from, 0, G[from].size() - 1});
}

int dfs(int v, int t, int f) {
  if(v == t) return f;
  used[v] = 1;
  for(int i = 0; i < (int) G[v].size(); i++) {
    edge& e = G[v][i];
    if(!used[e.to] && e.cap > 0) {
      used[e.to] = 1;
      int d = dfs(e.to, t, min(e.cap, f));
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
  ifstream fin ("stall4.in");
  ofstream fout ("stall4.out");
  fin >> N >> M;
  set<int> s;
  int K, to;
  for(int i = 1; i <= N; i++) {
    add_edge(0, M + i);
    fin >> K;
    for(int j = 0; j < K; j++) {
      fin >> to;
      s.insert(to);
      add_edge(M + i, to);
    }
  }
  set<int>::iterator it = s.begin();
  for(; it != s.end(); it++) add_edge(*it, M + N + 1);
  int f = 0;
  for(;;) {
    memset(used, 0, sizeof used);
    int d = dfs(0, M + N + 1, inf);
    if(d == 0) break;
    f += d;
  }
  fout << f << endl;

  return 0;
}
