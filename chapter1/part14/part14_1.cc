/*
ID: Zhi Li
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

bool mask[125000];

int main(void) {
  ifstream fin ("ariprog.in");
  ofstream fout ("ariprog.out");
  int N, M;
  fin >> N >> M;
  int range = M * M * 2;

  vector<pair<int, int> > ans;

  for(int i = 0; i <= M; i++)
    for(int j = i; j <= M; j++)
      mask[i * i + j * j] = 1;


  for(int d = 1; d <= range / (N - 1) + 1; d++) {
    for(int start = 0; start + (N - 1) * d <= range; start++) {
      int k;
      for(k = 0; k < N; k++) {
        int ele = start + k * d;
        if(mask[ele] == 0) break;
      }
      if(k >= N) ans.push_back(make_pair(start, d));
    }
  }

  if(ans.empty()) fout << "NONE" << endl;
  else {
    for(int i = 0; i < (int) ans.size(); i++)
      fout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
