/*
ID: Zhi Li
PROG: range
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, ele;
string line;
int graph[255][255], f[255][255];
int ans[255];

int main(void) {
  ifstream fin ("range.in");
  ofstream fout ("range.out");
  fin >> N;
  for(int i = 1; i <= N; i++) {
    fin >> line;
    for(int j = 1; j <= N; j++) {
      ele = line[j - 1] == '1';
      graph[i][j] = ele;
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (ele == 1);
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) if(graph[i][j] == 1) {
        for(int m = i + 1; m <= N; m++) {
          int n = m + j - i;
          if(graph[m][n] == 1) {
            int s = (m - i + 1) * (n - j + 1);
            int cnt = f[m][n] - f[m][j - 1] - f[i - 1][n] + f[i - 1][j - 1];
            if(cnt == s) ans[m - i + 1]++;
          }
        }
      }
  }

  for(int i = 2; i < 255; i++) {
    if(ans[i]) fout << i << " " << ans[i] << endl;
  }

  return 0;
}
