/*
ID: Zhi Li
PROG: game1
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
int N;

int dp[205][205], sum[205][205];
int data[205];

int main(void) {
  ifstream fin ("game1.in");
  ofstream fout ("game1.out");
  fin >> N;
  for(int i = 1; i <= N; i++) fin >> data[i];

  for(int from = N; from >= 1; from--) {
    for(int to = from + 1; to <= N + 1; to++) {
      sum[from][to] = sum[from][to - 1] + data[to - 1];
      dp[from][to] = sum[from][to] - min(dp[from + 1][to], dp[from][to - 1]);
    }
  }

  fout << dp[1][N + 1] << " " << sum[1][N + 1] - dp[1][N + 1] << endl;

  return 0;
}
