/*
ID: Zhi Li
PROG: lamps
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

int N, C;
int start[] = {1, 1, 2, 1}, inc[]   = {1, 2, 2, 3};

void trans(string& state, int ith) {
  for(int i = start[ith]; i <= N; i += inc[ith]) {
    state[i] = (state[i] == '0') + '0';
  }
}

bool check(string state, vector<int>& on, vector<int>& off) {
  for(int i = 0; i < (int) on.size(); i++) if(state[on[i]] != '1') return 0;
  for(int j = 0; j < (int) off.size(); j++) if(state[off[j]] != '0') return 0;
  return 1;
}

int main(void) {
  ifstream fin ("lamps.in");
  ofstream fout ("lamps.out");
  fin >> N >> C;
  int ele;
  vector<int> on, off;
  int cnt = 0;
  while(cnt < 2) {
    fin >> ele;
    if(ele == -1) cnt++;
    if(ele != -1 && cnt == 0) on.push_back(ele);
    if(ele != -1 && cnt == 1) off.push_back(ele);
  }

  vector<string> res;
  for(int i = 0; i <= 1; i++) {
    for(int j = 0; j <= 1; j++) {
      for(int k = 0; k <= 1; k++) {
        string state(N + 1, '1');
        int cnt = 0;
        int m = i ^ j ^ k ^ (1 & C);
        if(cnt < C && i & 1) { trans(state, 0); cnt++; }
        if(cnt < C && j & 1) { trans(state, 1); cnt++; }
        if(cnt < C && k & 1) { trans(state, 2); cnt++; }
        if(cnt < C && m & 1) { trans(state, 3); cnt++; }
        if(check(state, on, off)) res.push_back(state.substr(1, state.size() - 1));
      }
    }
  }

  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  if(res.size() == 0) fout << "IMPOSSIBLE" << endl;
  else {
    for(int i = 0; i < (int) res.size(); i++)
      fout << res[i] << endl;
  }

  return 0;
}
