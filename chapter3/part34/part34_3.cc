/*
ID: Zhi Li
PROG: rockers
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

int N, T, M;
int minutes[22];

int main(void) {
  ifstream fin ("rockers.in");
  ofstream fout ("rockers.out");
  fin >> N >> T >> M;
  for(int i = 0; i < N; i++) fin >> minutes[i];
  int ans = 0;
  for(int i = (1 << N) - 1; i > 0; i--) {
    int cnt = 1, rem = T, flag = 1;
    for(int k = (N - 1); flag && k >= 0; k--) {
      int j = 1 << k;
      if(i & j) {
        if(rem >= minutes[k]) rem -= minutes[k];
        else if(cnt < M && T >= minutes[k]) { cnt++; rem = T - minutes[k]; }
        else flag = 0;
      }
    }
    if(flag) ans = max(ans, __builtin_popcount(i));
  }

  fout << ans << endl;

  return 0;
}
