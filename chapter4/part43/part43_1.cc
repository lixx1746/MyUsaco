/*
ID: Zhi Li
PROG: buylow
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[5050], data[5050];
string cnt[5050];
int N;

string add_str(string a, string b) {
  string ans;
  int ai = a.size() - 1, bi = b.size() - 1, c = 0;
  while(ai >= 0 || bi >= 0) {
    int da = ai >= 0 ? a[ai] - '0' : 0;
    int db = bi >= 0 ? b[bi] - '0' : 0;
    int d = da + db + c;
    c = d / 10;
    ans.push_back(d % 10 + '0');
    ai--; bi--;
  }
  if(c) ans.push_back('1');
  reverse(ans.begin(), ans.end());
  while(ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
  return ans;
}

int main(void) {
  ifstream fin ("buylow.in");
  ofstream fout ("buylow.out");
  fin >> N;
  int ans = 1;
  for(int i = 1; i <= N; i++) fin >> data[i];

  for(int i = 1; i <= N; i++) {
    dp[i] = 1;
    for(int j = i - 1; j >= 1; j--) {
      if(data[i] < data[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }
  for(int i = 1; i <= N; i++) cnt[i] = "0";
  for(int i = 1; i <= N; i++) {
    if(dp[i] == 1) cnt[i] = "1";
    else {
      int query = dp[i] - 1, pre = -1;
      for(int j = i - 1; j >= 1; j--) {
        if(data[j] > data[i] && data[j] != pre && dp[j] == query) {
          pre = data[j];
          cnt[i] = add_str(cnt[i], cnt[j]);
        }
      }
    }
  }
  string total = "0";
  int query = ans, pre = -1;
  for(int j = N; j >= 1; j--) {
    if(data[j] != pre && dp[j] == query) {
      pre = data[j];
      total = add_str(total, cnt[j]);
    }
  }

  fout << ans << " " << total << endl;

  return 0;
}
