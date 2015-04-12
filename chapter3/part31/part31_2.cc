/*
ID: Zhi Li
PROG: inflate
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
int M, N;
const int MAX_N = 10010;
int score[MAX_N], minute[MAX_N];
int dp[MAX_N];

int main(void) {
  ifstream fin ("inflate.in");
  ofstream fout ("inflate.out");
  fin >> M >> N;
  for(int i = 1; i <= N; i++) fin >> score[i] >> minute[i];

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= M; j++) {
      if(j >= minute[i]) dp[j] = max(score[i] + dp[j - minute[i]], dp[j]);
    }
  }

  fout << dp[M] << endl;

  return 0;
}
