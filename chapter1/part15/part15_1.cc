/*
ID: Zhi Li
PROG: numtri
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
int dp[1010];

int main(void) {
  ifstream fin ("numtri.in");
  ofstream fout ("numtri.out");
  fin >> N;
  int ele, ans = 0;
  vector<vector<int> > data(N, vector<int> ());
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      fin >> ele;
      ans = max(ele, ans);
      data[i].push_back(ele);
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = i; j >= 0; j--) {
      if(j == 0) dp[j] += data[i][j];
      else dp[j] = max(dp[j], dp[j - 1]) + data[i][j];
      ans = max(ans, dp[j]);
    }
  }
  fout << ans << endl;
  return 0;
}
