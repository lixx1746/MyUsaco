/*
ID: Zhi Li
PROG: kimbits
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
long long N, L, I;
long long dp[35][35];
long long acc[35][35];

int main(void) {
  ifstream fin ("kimbits.in");
  ofstream fout ("kimbits.out");
  fin >> N >> L >> I;
  for(int i = 0; i < 35; i++) dp[i][0] = 1;
  for(int i = 1; i < 35; i++) {
    for(int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  for(int i = 0; i < 35; i++) acc[i][0] = 1;
  for(int i = 1; i < 35; i++) {
    for(int j = 1; j <= i; j++) {
      acc[i][j] = acc[i][j - 1] + dp[i][j];
    }
  }

  string ans(N, '0');
  for(int i = 1, cnt = 0; i <= N; i++) {
    int id = min(L - cnt, N - i);
    if(cnt < L && acc[N - i][id] < I) {
      ans[i - 1] = '1';
      I = I - acc[N - i][id];
      cnt++;
    }
  }
  fout << ans << endl;

  return 0;
}
