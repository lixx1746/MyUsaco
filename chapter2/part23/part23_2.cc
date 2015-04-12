/*
ID: Zhi Li
PROG: nocows
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

const int mod = 9901;
int N, K;
long long dp[205][105];

void add(long long& a, long long b) {
  a = (a + b) % mod;
}

int main(void) {
  ifstream fin ("nocows.in");
  ofstream fout ("nocows.out");
  fin >> N >> K;
  dp[1][1] = 1;
  for(int i = 3; i <= 200; i += 2) {
    for(int k = 1; k <= (i + 1) / 2; k++) {
      for(int l = 1; l < i - 1; l += 2) {
        add(dp[i][k], dp[l][k - 1] * 1ll * dp[i - l - 1][k - 1]);
        for(int j = 1; j < k - 1 &&  j <= (l + 1) / 2; j++) {
          add(dp[i][k], dp[l][j] * 2ll *  dp[i - l - 1][k - 1]);
        }
      }
    }
  }

  fout << dp[N][K] << endl;

  return 0;
}
