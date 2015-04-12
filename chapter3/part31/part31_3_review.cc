/*
ID: Zhi Li
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
int K, N;
int s[105];

map<long long, bool> used;

int main(void) {
  ifstream fin ("humble.in");
  ofstream fout ("humble.out");

  fin >> K >> N;
  vector<long long> cur;
  for(int i = 0; i < K; i++) {
    fin >> s[i];
  }
  set<long long> res;
  res.insert(1ll);
  while(1) {
    int flag = 0;
    set<long long>::iterator it = res.begin();
    for(; it != res.end(); it++) {
      for(int k = 0; k < K; k++) {
        long long ele = (*it) * s[k];
        if ((int) res.size() <= N) { res.insert(ele); flag = 1; }
        else if(ele >= *res.rbegin()) break;
        else if(!res.count(ele) && ele < (*res.rbegin())) {
          set<long long>::iterator last = res.end();
          last--;
          res.erase(last);
          res.insert(ele);
          flag = 1;
        }
      }
    }
    if(!flag) break;
  }

  fout << *(res.rbegin()) << endl;
  return 0;

}
