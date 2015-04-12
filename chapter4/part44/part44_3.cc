/*
ID: Zhi Li
PROG: frameup
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
int H, W, total_cnt;
char G[35][35];
int used[26], diff[26], indegree[26];
vector<int> DAG[26];
typedef struct state { int left_i, left_j, right_i, right_j; } State;
State pos[26];
set<string> res;
int acc[26], visited[26];

void dfs(string &path) {
  if((int) path.size() == total_cnt) {
    res.insert(path);
    return;
  }
  for(int k = 0; k < 26; k++) {
    if(!used[k]) continue;
    if(!visited[k] && acc[k] == indegree[k]) {
       int len = path.size();
       path.push_back((char) (k + 'A'));
       visited[k] = 1;
       for(int j = 0; j < (int) DAG[k].size(); j++) {
         int to = DAG[k][j];
         acc[to]++;
       }
       dfs(path);
       visited[k] = 0;
       path.resize(len);
       for(int j = 0; j < (int) DAG[k].size(); j++) {
         int to = DAG[k][j];
         acc[to]--;
       }
    }
  }
}

int main(void) {
  ifstream fin ("frameup.in");
  ofstream fout ("frameup.out");
  fin >> H >> W;
  string line;
  char c;
  for(int i = 0; i < H; i++) {
   fin >> line;
   for(int j = 0; j < W; j++) {
     G[i][j] = c = line[j];
     if(c == '.') continue;
     int id = c - 'A';
     if(!used[id]) {
       used[id] = 1;
       total_cnt++;
       pos[id].left_i = i;  pos[id].left_j = j;
     }
     else {
       pos[id].left_i = min(pos[id].left_i, i);
       pos[id].left_j = min(pos[id].left_j, j);
       pos[id].right_i = max(pos[id].right_i, i);
       pos[id].right_j = max(pos[id].right_j, j);
     }
   }
  }

  for(int i = 0; i < 26; i++) {
    if(!used[i]) continue;
    vector<char> dif;
    int start_i = pos[i].left_i, start_j = pos[i].left_j;
    int final_i = pos[i].right_i, final_j = pos[i].right_j;
    for(int j = start_j; j < final_j; j++)
      if(G[start_i][j] != i + 'A') dif.push_back(G[start_i][j]);
    for(int k = start_i; k < final_i; k++)
      if(G[k][final_j] != i + 'A') dif.push_back(G[k][final_j]);
    for(int j = final_j; j > start_j; j--)
      if(G[final_i][j] != i + 'A') dif.push_back(G[final_i][j]);
    for(int k = final_i; k > start_i; k--)
      if(G[k][start_j] != i + 'A') dif.push_back(G[k][start_j]);
    sort(dif.begin(), dif.end());
    dif.erase(unique(dif.begin(), dif.end()), dif.end());
    for(int k = 0; k < (int) dif.size(); k++) {
      char from = (char) (i + 'A');
       int fromid = from - 'A', toid = dif[k] - 'A';
       DAG[fromid].push_back(toid);
       indegree[toid]++;
    }
  }

  string path;
  dfs(path);
  set<string>::iterator it = res.begin();
  for(; it != res.end(); it++) {
    fout << *it << endl;
  }

  return 0;
}
