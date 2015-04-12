/*
ID: Zhi Li
PROG: subset
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

int N;
long long dp[42][810];

long long solve(const int& sum, int start, int sol) {
  if(dp[start][sol] != -1) return dp[start][sol];
  long long& ele = dp[start][sol];
  ele = 0;
  if(sol + start == sum) ele = 1;
  else if (sol + start < sum) {
    for(int j = start + 1; j <= N; j++) {
      ele += solve(sum, j, sol + start);
    }
  }
  return ele;
}

int main(void) {
  ifstream fin ("subset.in");
  ofstream fout ("subset.out");
  fin >> N;
  memset(dp, -1, sizeof dp);
  int sum = (N + 1) * N / 2;
  if(sum & 1) fout << 0 << endl;
  else fout << solve(sum / 2, 1, 0) << endl;
  return 0;
}
