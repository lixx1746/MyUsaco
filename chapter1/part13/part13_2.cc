/*
ID: Zhi Li
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pii;

int main(void) {
  ifstream fin ("barn1.in");
  ofstream fout ("barn1.out");
  int M, S, C, ele;
  fin >> M >> S >> C;
  vector<int> d;
  vector<Pii> seg;
  for(int i = 0; i < C; i++) { fin >> ele; d.push_back(ele); }
  sort(d.begin(), d.end());
  for(int i = 0; i < C;) {
    int l = i, r = i;
    while(r < C && d[r] - d[l] == r - l) r++;
    seg.push_back(make_pair(d[l], d[r - 1]));
    i = r;
  }
  int gap = 2;
  while((int) seg.size() > M) {
    int len = seg.size(), i;
    sort(seg.begin(), seg.end());
    for(i = 1; i < len; i++) {
      Pii cur = seg[i];
      Pii pre = seg[i - 1];
      if(cur.first - pre.second == gap) {
        seg.erase(seg.begin() + i);
        seg.erase(seg.begin() + i - 1);
        seg.push_back(make_pair(pre.first, cur.second));
        break;
      }
    }
    if(i == len) gap++;
  }

  int ans = 0;
  for(int i = 0; i < (int) seg.size(); i++) {
    ans += seg[i].second - seg[i].first + 1;
  }

  fout << ans << endl;
  return 0;
}
