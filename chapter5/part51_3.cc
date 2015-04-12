/*
ID: Zhi Li
PROG: theme
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

int notes[5010], N;

int main(void) {
  ifstream fin ("theme.in");
  ofstream fout ("theme.out");
  fin >> N;
  for(int i = 0; i < N; i++) fin >> notes[i];
  int ans = 1;
  for(int i = 1; i < N; i++) {
    int len = 1;
    for(int j = N - i - 1 - 1; j >= 0; j--) {
      if(notes[j] - notes[j + 1] == notes[j + i] - notes[j + i + 1]) {
        len++;
        if(len > i) len = i;
        ans = max(ans, len);
      }
      else len = 1;
    }
  }
  fout << (ans < 5 ? 0 : ans) << endl;;
  return 0;
}
