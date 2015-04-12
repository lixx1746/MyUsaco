/*
ID: Zhi Li
PROG: hamming
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

int N, B, D;

inline int ham_dist(int a, int b) {
  int cnt = 0;
  for(int i = 0; i < B; i++) {
    int mask = 1 << i;
    if((mask & a) != (mask & b)) cnt++;
  }
  return cnt;
}

int ans[65];

int main(void) {
  ifstream fin ("hamming.in");
  ofstream fout ("hamming.out");
  fin >> N >> B >> D;
  for(int i = 0; i < (1 << B); i++) {
    int cnt = 1;
    ans[0] = i;
    for(int j = i + 1; cnt < N && j < (1 << B); j++) {
      int k;
      for(k = 0; k < cnt; k++) {
        if(ham_dist(ans[k], j) < D) break;
      }
      if(k == cnt) ans[cnt++] = j;
    }
    if(cnt == N) break;
  }
  for(int i = 0; i < N; i++) {
    if(i != 0 && i % 10 == 0) fout << endl;
    if(i % 10 != 0) fout << " ";
    fout << ans[i];
  }
  fout << endl;
  return 0;
}
