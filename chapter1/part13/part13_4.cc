/*
ID: Zhi Li
PROG: combo
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

typedef pair<int, pair<int, int> > PiP;

int N;

void helper(int l, int m, int r, set<PiP> &s) {
  for(int ll = l - 2; ll <= l + 2; ll++)
    for(int mm = m - 2; mm <= m + 2; mm++)
      for(int rr = r - 2; rr <= r + 2; rr++) {
        int tmpl = ll, tmpm = mm, tmpr = rr;
        if(ll <= 0 || ll > N) tmpl += (ll <= 0 ? N : -N);
        if(rr <= 0 || rr > N) tmpr += (rr <= 0 ? N : -N);
        if(mm <= 0 || mm > N) tmpm += (mm <= 0 ? N : -N);
        if(tmpl < 1 || tmpl > N || tmpr < 1 || tmpr > N || tmpm < 1 || tmpm > N) continue;
        s.insert(make_pair(tmpl, make_pair(tmpm, tmpr)));
      }
}

int main(void) {
  ifstream fin ("combo.in");
  ofstream fout ("combo.out");
  int l, m, r;
  fin >> N;
  set<PiP> s;
  fin >> l >> m >> r;
  helper(l, m, r, s);
  fin >> l >> m >> r;
  helper(l, m, r, s);
  fout << s.size() << endl;
  return 0;
}
