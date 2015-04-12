/*
ID: Zhi Li
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> Pii;

int min(int a, int b) { return a <= b ? a : b; }

int main(void) {
  ifstream fin ("milk.in");
  ofstream fout ("milk.out");
  int N, M, w, c;
  fin >> N >> M;
  vector<Pii> data;
  for(int i = 0; i< M; i++) {
    fin >> c >> w;
    data.push_back(make_pair(c, w));
  }
  sort(data.begin(), data.end());
  int ans = 0;
  for(int i = 0; i < (int) data.size(); i++) {
    if(N == 0) break;
    int val = min(N, data[i].second);
    N -= val;
    ans += val * data[i].first;
  }
  fout << ans << endl;
  return 0;
}
