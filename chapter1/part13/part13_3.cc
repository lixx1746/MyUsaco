/*
ID: Zhi Li
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) {
  ifstream fin ("crypt1.in");
  ofstream fout ("crypt1.out");
  int N, ele, res = 0;
  set<int> lookup;
  fin >> N;
  for(int i = 0; i < N; i++) { fin >> ele; lookup.insert(ele); }
  vector<int> s(lookup.begin(), lookup.end());
  int n = s.size();
  for(int i0 = 0; i0 < n; i0++) {
    int lower0 = s[i0];
    for(int i1 = 0; i1 < n; i1++) {
      int lower1 = s[i1];
      for(int j0 = 0; j0 < n; j0++) {
        int upper0 = s[j0];
        int part10 = lower0 * upper0;
        int part21 = lower1 * upper0;
        int ans0 = part10 % 10;
        if(!lookup.count(ans0) || !lookup.count(part21 % 10)) continue;
        for(int j1 = 0; j1 < n; j1++) {
          int upper1 = s[j1];
          int part11 = part10 / 10 + upper1 * lower0;
          int part22 = part21 / 10 + upper1 * lower1;
          int ans1 = (part21 + part11) % 10;
          if(!lookup.count(part11 % 10) || !lookup.count(part22 % 10) || !lookup.count(ans1)) continue;
          for(int j2 = 0; j2 < n; j2++) {
            int upper2 = s[j2];
            int part12 = part11 / 10 + lower0 * upper2;
            int part23 = part22 / 10 + lower1 * upper2;
            if(!lookup.count(part12) || !lookup.count(part23)) continue;
            int ans2 =( part12 + part22 % 10 + (part21 % 10 + part11 % 10) / 10) % 10;
            int ans3 = part23 + (part12 + part22 % 10) / 10;
            if(!lookup.count(ans2) || !lookup.count(ans3)) continue;
            res++;
          }
        }
      }
    }
  }
  fout << res << endl;

  return 0;
}
