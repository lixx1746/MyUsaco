/*
ID: Zhi Li
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main(void) {
  ifstream fin ("milk2.in");
  ofstream fout ("milk2.out");
  int N, s, t;
  fin >> N;
  vector<P> data;
  for(int i = 0; i < N; i++) {
    fin >> s >> t;
    data.push_back(make_pair(s, t));
  }
  sort(data.begin(), data.end());
  P pre = data[0];
  int ans1 = pre.second - pre.first, ans2 = 0;
  for(int i = 1; i < N; i++) {
    P cur = data[i];
    ans1 = max(ans1, cur.second - cur.first);
    if(pre.second < cur.first) {
      ans2 = max(ans2, cur.first - pre.second);
      pre = cur;
    }
    else {
      pre.second = max(pre.second, cur.second);
      ans1 = max(ans1, pre.second - pre.first);
    }
  }
  ans1 = max(ans1, pre.second - pre.first);
  fout << ans1 << " " << ans2 << endl;
  return 0;
}
