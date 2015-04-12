/*
ID: Zhi Li
PROG: frac1
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
int N;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a %  b); }
typedef pair<int, int> Pii;

bool mycomp(Pii a, Pii b) {
  double a1 =  1.0 * a.first / a.second;
  double b1 =  1.0 * b.first / b.second;
  return a1 < b1;
}

int main(void) {
  ifstream fin ("frac1.in");
  ofstream fout ("frac1.out");
  fin >> N;
  set<Pii> res;
  for(int de = N; de > 1; de--)
    for(int nu = 1; nu <= de; nu++) {
      int g = gcd(de, nu);
      res.insert(make_pair(nu / g, de / g));
    }

  vector<Pii> ans(res.begin(), res.end());
  sort(ans.begin(), ans.end(), mycomp);
  fout << "0/1" << endl;
  for(int i = 0; i < (int) res.size(); i++) {
    fout << ans[i].first << "/" << ans[i].second << endl;
  }
  return 0;
}
