/*
ID: Zhi Li
PROG: concom
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

typedef pair<int, int> Pii;

int N;
vector<Pii> graph[105], ans;
int start[105];

long long dis[105];
bool visited[105];

void dfs(int v) {
  visited[v] = 1;
  for(int i = 0; i < (int) graph[v].size(); i++) {
    int to = graph[v][i].first, len = graph[v][i].second;
    if(!visited[to]) {
      dis[to] += len;
      if(dis[to] > 50) dfs(to);
    }
  }
  visited[v] = 0;
}

int main(void) {
  ifstream fin ("concom.in");
  ofstream fout ("concom.out");
  fin >> N;
  int from, to, len;
  for(int i = 1; i <= N; i++) {
    fin >> from >> to >> len;
    start[from] = 1;
    graph[from].push_back(make_pair(to, len));
  }

  for(int i = 0; i < 105; i++) if(start[i]) {
    memset(dis, 0, sizeof(dis));
    dfs(i);
    for(int j = 0; j < 105; j++) if(dis[j] > 50) ans.push_back(make_pair(i, j));
  }

  sort(ans.begin(), ans.end());

   for(int i = 0; i < (int) ans.size(); i++)
     fout << ans[i].first << " " <<  ans[i].second << endl;

  return 0;
}
