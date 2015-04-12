/*
ID: Zhi Li
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

using namespace std;

int W, H;
int ex1 = -1, ex2 = -1;
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
vector<string> graph;
int iid[4010], jid[4010];
vector<int>  nei[4010];
bool visited[4010];
int dist_to_exit[4010];

typedef pair<int, int> Pii;

void bfs(int source) {
  queue<Pii> q;
  memset(visited, 0, sizeof visited);
  visited[source] = 1;
  q.push(make_pair(source, 0));
  while(!q.empty()) {
    Pii node = q.front();
    q.pop();
    int v = node.first, dis = node.second;
    dist_to_exit[v] = min(dist_to_exit[v], dis);
    for(int i = 0; i < (int) nei[v].size(); i++) {
      int to = nei[v][i];
      if(!visited[to]) {
        visited[to] = 1;
        q.push(make_pair(to, dis + 1));
      }
    }
  }
}


bool can_go(int from, int to) {
  int fi = iid[from], fj = jid[from];
  int toi = iid[to], toj = jid[to];
  int xi = fi - toi, yi = fj - toj;
  int midi = (fi + toi) / 2, midj = (fj + toj) / 2;
  if(xi * xi + yi * yi <= 4 && graph[midi][midj] == ' ') return true;
  else return false;
}

bool is_exit(int i, int j, int d) {
  int tempi = i + di[d];
  int tempj = j + dj[d];
  if((tempi == 0 || tempi == H - 1 || tempj == 0 || tempj == W - 1) && graph[tempi][tempj] == ' ')
    return true;
  else return false;
}

int main(void) {
  ifstream fin ("maze1.in");
  ofstream fout ("maze1.out");
  fin >> W >> H;
  W = 2 * W + 1;
  H = 2 * H + 1;
  fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  int row = 0, cnt = 0;
  while(!fin.eof()) {
    string line;
    getline(fin, line);
    if(row & 1) {
      for(int i = 1; i < W - 1; i += 2) {
        if(line[i] == ' ') {
          iid[cnt] = row;
          jid[cnt] = i;
          cnt++;
        }
      }
    }
    row++;
    graph.push_back(line);
  }

  for(int i = 0 ; i < cnt; i++) {
    for(int d = 0; d <= 3; d++) {
      if(ex1 == -1 && is_exit(iid[i], jid[i], d)) ex1 = i;
      else if(ex2 == -1 && is_exit(iid[i], jid[i], d)) ex2 = i;
    }
  }

  for(int from = 0; from < cnt; from++) {
    for(int to = from + 1; to < cnt; to++) {
      if(can_go(from, to)) {
        nei[from].push_back(to);
        nei[to].push_back(from);
      }
    }
  }


  for(int i =0 ; i < 4010; i++) dist_to_exit[i] = 987654321;
  bfs(ex1); bfs(ex2);
  int ans =0;
  for(int i = 0; i < cnt; i++) ans = max(ans, dist_to_exit[i]);
  fout << ans + 1 << endl;

  return 0;
}
