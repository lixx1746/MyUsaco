/*
ID: Zhi Li
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> ls;
string seq;
int N;
int dp[200010];

bool start_with(int start, string pri) {
  int m = pri.size();
  for(int i = 0; i < m; i++) if(seq[start + i] != pri[i]) return 0;
  return 1;
}

int solve(int start) {
  if(dp[start] != -1) return dp[start];
  int& ele = dp[start];
  ele = 0;
  if(start >= N) return ele;
  for(int i = 0; i < (int) ls.size(); i++) {
    int len = ls[i].size();
    if(len <= N - start && start_with(start, ls[i])) {
      ele = max(ele, len + solve(start + len));
    }
  }
  return ele;
}

int main(void) {
  ifstream fin ("prefix.in");
  ofstream fout ("prefix.out");
  string str;

  while(fin >> str && str != ".") ls.push_back(str);
  while(fin >> str) seq += str;
  N = seq.size();

  memset(dp, -1, sizeof dp);

  fout << solve(0) << endl;

  return 0;
}
