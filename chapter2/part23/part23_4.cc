/*
ID: Zhi Li
PROG: money
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

int V, N;
int data[50];
long long dp[50][10010];

int main(void) {
  ifstream fin ("money.in");
  ofstream fout ("money.out");
  fin >> V >> N;
  for(int i = 1; i <= V; i++) fin >> data[i];

  for(int i = 0; i < V; i++) dp[i][0] = 1;
  for(int i = 1; i <= V; i++) {
    for(int j = 0; j <= 10010; j++) {
      if(j < data[i]) dp[i][j] = dp[i - 1][j];
      else  dp[i][j] = dp[i - 1][j] + dp[i][j - data[i]];
    }
  }

  fout << dp[V][N] << endl;

  return 0;
}
