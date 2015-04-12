/*
ID: Zhi Li
PROG: cowtour
LANG: C++
*/

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

vector<string> graph;
double x[155], y[155];
double dist[155][155];
double dp[155];

const double inf = 9876543210e200;
int N;

double cacl_dis(int from, int to) {
  double fromx = x[from], fromy = y[from], tox = x[to], toy = y[to];
  double xgap = fromx - tox, ygap = fromy - toy;
  double xq = xgap  * xgap;
  double yq = ygap * ygap;
  return sqrt(xq + yq);
}

int main(void) {
  ifstream fin ("cowtour.in");
  FILE* fout = fopen ("cowtour.out","w");
  fin >> N;
  for(int i = 0; i < N; i++) fin >> x[i] >> y[i];
  fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  string line;
  while(fin >> line) graph.push_back(line);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(graph[i][j] == '0') {
       dist[i][j] = inf;
      }
      else {
        double dis = cacl_dis(i, j);
        dist[i][j] = dis;
      }
    }
  }

  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++) if(i != j && i != k && j != k)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  double ans1 = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      if(dist[i][j] < inf) {
        dp[i] = max(dp[i], dist[i][j]);
        ans1 = max(ans1, dp[i]);
      }
  }

  double ans = inf;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i != j && dist[i][j] >= inf) {
        ans = min(ans, cacl_dis(i, j) + dp[i] + dp[j]);
      }
    }
  }

  fprintf(fout, "%.6f\n", max(ans, ans1));

  return 0;
}
