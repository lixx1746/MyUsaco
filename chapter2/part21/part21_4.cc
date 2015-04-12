/*
ID: Zhi Li
PROG: holstein
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
int N, F;
typedef struct feed {
  int vit[30];
} Feed;

int dp[1 << 15][25];
int req[30];
Feed feeds[20];

int main(void) {
  ifstream fin ("holstein.in");
  ofstream fout ("holstein.out");
  fin >> N;
  for(int i = 0; i < N; i++) fin >> req[i];
  fin >> F;
  for(int i = 0; i < F; i++)
    for(int j = 0; j < N; j++) fin >> feeds[i].vit[j];

  int ans = F + 1, id = (1 << F) - 1;
  for(int k = 0; k < (1 << F); k++)
    for(int j = 0; j < F; j++) {
      int cnt = 0;
      for(int i = 0; i < N; i++) {
        if(!((1 << j) & k)) dp[(1 << j) | k][i] = dp[k][i] + feeds[j].vit[i];
        if(dp[k][i] >= req[i]) cnt++;
      }
      if(cnt == N && ans > __builtin_popcount(k)) {
      ans = __builtin_popcount(k);
      id = k;
      }
    }

  vector<int> res;
  for(int i = 1; i <= F; i++) if((1 << (i - 1)) & id) res.push_back(i);

  fout << ans << " ";
  for(int i = 0; i < ans; i++) {
    if(i != 0) fout << " ";
    fout << res[i];
  }

  fout << endl;
  return 0;
}
