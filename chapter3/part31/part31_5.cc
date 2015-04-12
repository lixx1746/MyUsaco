/*
ID: Zhi Li
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int K, N;
int stamps[55];
const int MAX_NUM = 2000010;
int dp[MAX_NUM];

int main(void) {
  ifstream fin ("stamps.in");
  ofstream fout ("stamps.out");
  fin >> K >> N;
  memset(dp, 0x7F, sizeof dp);
  for(int i = 0; i < N; i++) fin >> stamps[i];
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = stamps[i]; j < MAX_NUM; j++) {
      dp[j] = min(dp[j], dp[j - stamps[i]] + 1);
    }
  }

  for(int i = 0; i < 100; i++) cout << dp[i] << " ";
  cout << endl;

  int ans = 1;
  for(; ans < MAX_NUM; ans++) if(dp[ans] > K) break;
  fout << ans - 1 << endl;
  return 0;
}
