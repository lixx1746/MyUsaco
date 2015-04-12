/*
ID: Zhi Li
PROG: castle
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX_V = 55;
int M, N;

int graph[MAX_V][MAX_V];
int data[MAX_V][MAX_V];
int cnt[MAX_V * MAX_V];

int X[] = { 0, -1, 0, 1 };
int Y[] = { -1, 0, 1, 0 };

int dfs(int x, int y, int ele) {
  int total = 0;
  if(graph[x][y] < 0) {
    total++;
    graph[x][y] = ele;
    int val = data[x][y];
    for(int d = 0; d < 4; d++) {
      if(!(val & (1 << d))) total += dfs(x + X[d], y + Y[d], ele);
    }
  }
  return total;
}

int main(void) {
  ifstream fin ("castle.in");
  ofstream fout ("castle.out");
  int val;
  fin >> M >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {
      fin >> val;
      data[i][j] = val;
      graph[i][j] = -1;
    }

  int comp = 0, num = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      int tmp;
      if(graph[i][j] == -1) {
        tmp = dfs(i, j, comp);
        cnt[comp] = tmp;
        comp++;
      }
      num = max(num, tmp);
    }
  }
  int ans = 0, x, y;
  char c;
  for(int j = 0; j < M; j++) {
    for(int i = N - 1; i >= 0; i--) {
      int val = data[i][j];
      if((val & (1 << 1)) && i > 0 && graph[i - 1][j] != graph[i][j]) {
        int temp = cnt[graph[i - 1][j]] + cnt[graph[i][j]];
        if(ans < temp) {
          ans = temp;
          c = 'N';
          x = i;
          y = j;
        }
      }
      if((val & (1 << 2)) && j < M  - 1 && graph[i][j] != graph[i][j + 1]) {
        int temp = cnt[graph[i][j]] + cnt[graph[i][j + 1]];
        if(ans < temp) {
          ans = temp;
          c = 'E';
          x = i;
          y = j;
        }
      }
    }
  }

  fout << comp << endl;
  fout << num << endl;
  fout << ans << endl;
  fout << x + 1 << " " << y + 1 << " " << c << endl;

  return 0;
}
