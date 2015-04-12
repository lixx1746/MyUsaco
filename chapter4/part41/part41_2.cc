/*
ID: Zhi Li
PROG: fence6
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int best = 30000;

set<int> graph[105][2];
int len[105], visited[105][2];

void dfs(int edge, const int anc, int path_sum) {
  path_sum += len[edge];
  if(path_sum >= best) return;
  int choose_one = !visited[edge][0] ? 0 : 1;
  visited[edge][choose_one] = 1;
  set<int>::iterator it = graph[edge][choose_one].begin();
  for(; it != graph[edge][choose_one].end(); it++) {
    int l = *it;
    int which = graph[l][0].count(edge) != 0 ? 0 : 1;
    visited[l][which] = 1;
    if(!visited[l][1 - which]) {
      if(graph[l][1 - which].count(anc)) {
        best = min(best, path_sum + len[l]);
       return;
      }
      dfs(l, anc, path_sum);
    }
    visited[l][which] = 0;
  }
  visited[edge][choose_one] = 0;
}


int main(void) {
  ifstream fin ("fence6.in");
  ofstream fout ("fence6.out");
  fin >> N;
  int id, l, N1, N2, f, t;
  for(int i = 1; i <= N; i++) {
    fin >> id >> l;
    len[id] = l;
    fin >> N1 >> N2;
    for(int n1 = 1; n1 <= N1; n1++) {
      fin >> f;
      graph[id][0].insert(f);
    }
    for(int n2 = 1; n2 <= N2; n2++) {
      fin >> t;
      graph[id][1].insert(t);
    }
  }

  for(int i = 1; i <= N; i++) {
    memset(visited, 0, sizeof visited);
    if(len[i] != 0) dfs(i, i, 0);
  }

  fout << best << endl;

  return 0;
}
