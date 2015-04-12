/*
ID: Zhi Li
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
int N;
int X[13], Y[13];
int match[13], next_on_right[13];

bool has_cycle(void) {
  for(int i = 1; i <= N; i++) {
    int pos = i;
    for(int cnt = 0; cnt < N; cnt++)
      pos = next_on_right[match[pos]];
    if(pos) return true;
  }
  return false;
}

int solve(void) {
  int i, total = 0;
  for(i = 1; i <= N; i++) if(!match[i]) break;

  if(i > N) {
    if(has_cycle()) return 1;
    else return 0;
  }

  for(int j = i + 1; j <= N; j++) if(!match[j]) {
      match[i] = j;
      match[j] = i;
      total += solve();
      match[i] = match[j] = 0;
  }
  return total;
}
int main(void) {
  ifstream fin ("wormhole.in");
  fin >> N;
  for(int i = 1; i <= N; i++) fin >> X[i] >> Y[i];

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
        if(X[i] < X[j] && Y[i] == Y[j]) {
          if(!next_on_right[i] ||
             X[next_on_right[i]] > X[j]) next_on_right[i] = j;
        }
    }
  }
  ofstream fout ("wormhole.out");
  fout << solve() << endl;
  return 0;
}
