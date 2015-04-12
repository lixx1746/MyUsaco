/*
ID: Zhi Li
PROG: butter
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

typedef pair<long long, int> Pii;

vector<Pii> graph[850];
long long dist[850];
const long long inf = 123456789987654321;
int cow_pos[510];
int N, P, C;

struct mycomp {
  bool operator() (Pii a, Pii b) { return a.first > b.first; }
};


void bfs(int source) {
  for(int i = 0; i <= P; i++) dist[i] = inf;
  priority_queue<Pii, vector<Pii>, mycomp> q;
  q.push(make_pair(0, source));
  while(!q.empty()) {
    Pii node = q.top();
    q.pop();
    dist[node.second] = min(dist[node.second], node.first);
    for(int i = 0; i < (int) graph[node.second].size(); i++) {
      int to = graph[node.second][i].second;
      long long d = graph[node.second][i].first + node.first;
      if(dist[to] == inf) q.push(make_pair(d, to));
    }
  }
}

int main(void) {
  ifstream fin ("butter.in");
  ofstream fout ("butter.out");
  fin >> N >> P >> C;
  for(int i = 1; i <= N; i++) fin >> cow_pos[i];
  int to, from, len;
  for(int i = 0; i < C; i++) {
    fin >> from >> to >> len;
    graph[from].push_back(make_pair(len, to));
    graph[to].push_back(make_pair(len, from));
  }
  long long ans = inf;
  for(int i = 1; i <= P; i++) {
    bfs(i);
    long long tmp = 0;
    for(int j = 1; j <= N; j++) {
      tmp += dist[cow_pos[j]];
      if(tmp > ans) break;
    }
    if(tmp < ans) ans = tmp;
  }

  fout << ans << endl;

  return 0;
}
