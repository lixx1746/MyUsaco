/*
ID: Zhi Li
PROG: race3
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int G[55][55],dist[55][55];
int visited[55];
int from, to;
long long ans1 = (1LL << 55) - 1;

void dfs(int v, int t, long long path, long long& ans) {
  path |= (1LL << v);
  visited[v] = 1;
  if(v == t) {
    ans |= path;
    ans1 &= path;
    return;
  }
  for(int i = 0; i < from; i++)
    if(!visited[i] && G[v][i]) {
      visited[i] = 1;
      dfs(i, t, path, ans);
      visited[i] = 0;
    }
  path &= ~(1LL << v);
  visited[v] = 0;
}

bool check(int node, const int v) {
  if(node == from - 1) return 1;
  visited[node] = 1;
  for(int i = 0; i < from; i++) if(i != v) {
      if(G[node][i] && !visited[i]) {
        visited[i] = 1;
        if(check(i, v)) return 1;
      }
    }
  return 0;
}


int main(void) {
  ifstream fin ("race3.in");
  ofstream fout ("race3.out");
  memset(dist, 0x3F, sizeof dist);
  while(true) {
    fin >> to;
    if(to == -1) break;
    if(to == -2) { from++; continue; }
    if(from != to)G[from][to] = 1;
    if(from != to) dist[from][to] = 0;
  }

  for(int k = 0; k < from; k++) {
    for(int i = 0; i < from; i++) {
      for(int j = 0; j < from; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }


  long long sbefore = 0LL, safter = 0LL;
  vector<int> res1, res2;
  for(int i = 1;  i < from - 1; i++) {
    memset(visited, 0, sizeof visited);
    if(!check(0, i)) res1.push_back(i);
  }

  for(int i = 0;  i < (int) res1.size(); i++) {
    memset(visited, 0, sizeof visited);
    sbefore = 0LL; safter = 0LL;
    dfs(0, res1[i], 0LL, sbefore);
    for(int k = 0; k < from; k++) if(!dist[res1[i]][k]) safter |= (1LL << k);

    int flag = 1;
    for(int f = 0; flag && f < from; f++) if(f != res1[i] && (sbefore & (1LL << f))) {
        for(int t = 0; flag && t < from; t++) if(t != res1[i] && (safter & (1LL << t))) {
            if(!dist[t][f]) { flag = 0; break; }
          }
      }
    if(flag) res2.push_back(res1[i]);
  }

  fout << res1.size();
  for(int i = 0; i < (int) res1.size(); i++) fout << " " << res1[i];
  fout << endl;
  fout << res2.size();
  for(int i = 0; i < (int) res2.size(); i++) fout << " " << res2[i];
  fout << endl;
  return 0;
}
