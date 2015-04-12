/*
ID: Zhi Li
PROG: fence
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>

using namespace std;

vector<int> graph[550];
int P;
int ans[1300], cirpos = 0;

void find_cir(int node) {
  while(!graph[node].empty()) {
    int to = (*graph[node].begin());
    graph[node].erase(graph[node].begin());
    graph[to].erase(find(graph[to].begin(), graph[to].end(), node));
    sort(graph[to].begin(), graph[to].end());
    find_cir(to);
  }
  ans[cirpos++] = node;
}


int main(void) {
  ifstream fin ("fence.in");
  ofstream fout ("fence.out");
  fin >> P;
  int from, to;
  for(int i = 0; i < P; i++) {
    fin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  int start = -1, tmp = -1;
  for(int i = 0; i < 510; i++) {
    if(graph[i].size()) {
      sort(graph[i].begin(), graph[i].end());
      if(tmp == -1) tmp = i;
      if((graph[i].size() & 1)) { start = i; break; }
    }
  }
  if(start == -1) start = tmp;
  find_cir(start);
  reverse(ans, ans + cirpos);
  for(int i = 0; i < cirpos; i++) {
    fout << ans[i] << endl;
  }

  return 0;
}
