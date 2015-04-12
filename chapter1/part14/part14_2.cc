/*
ID: Zhi Li
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
int A, B, C;
int visited[25][25][25];
typedef pair<int, pair<int, int> > PiP;
inline PiP mk(int a, int b, int c) { return make_pair(a, make_pair(b, c)); }
inline int sf(PiP p) { return p.second.first; }
inline int ss(PiP p) { return p.second.second; }

int main(void) {
  ifstream fin ("milk3.in");
  ofstream fout ("milk3.out");
  fin >> A >> B >> C;
  vector<int> res;
  queue<PiP> q;
  q.push(mk(0, 0, C));
  visited[0][0][C] = 1;
  while(!q.empty()) {
    PiP t = q.front();
    q.pop();
    int a = t.first, b = sf(t), c = ss(t);
    if(a == 0) res.push_back(c);
    if(a > 0) {
      int tmp = min(a, B - b), tmp1 = min(a, C - c);
      int& r11 = visited[a - tmp][b + tmp][c], r12 = visited[a - tmp1][b][c + tmp1];
      if(!r11) { r11 = 1; q.push(mk(a - tmp, b + tmp, c)); }
      if(!r12) { r12 = 1; q.push(mk(a - tmp1, b, c + tmp1)); }
    }
    if(b > 0) {
      int tmp = min(b, A - a), tmp1 = min(b, C - c);
      int& r21 = visited[a + tmp][b - tmp][c], r22 = visited[a][b - tmp1][c + tmp1];
      if(!r21) { r21 = 1; q.push(mk(a + tmp, b - tmp, c)); }
      if(!r22) { r22 = 1; q.push(mk(a, b - tmp1, c + tmp1)); }
    }
    if(c > 0) {
      int tmp = min(c, A - a), tmp1 = min(c, B - b);
      int& r31 = visited[a + tmp][b][c - tmp], r32 = visited[a][b + tmp1][c - tmp1];
      if(!r31) { r31 = 1; q.push(mk(a + tmp, b, c - tmp)); }
      if(!r32) { r32 = 1; q.push(mk(a, b + tmp1, c - tmp1)); }
    }
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  for(int i = 0; i < (int) res.size(); i++) {
    if(i > 0) fout << " ";
    fout << res[i];
  }
  fout << endl;
  return 0;
}
