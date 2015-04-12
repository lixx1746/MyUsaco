/*
ID: Zhi Li
PROG: nuggets
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
int N, ele;
vector<int> options;
int cando[67000];

int main(void) {
  ifstream fin ("nuggets.in");
  ofstream fout ("nuggets.out");
  fin >> N;
  for(int i = 0; i < N; i++) { fin >> ele; options.push_back(ele); }
  sort(options.begin(), options.end());
  options.erase(unique(options.begin(), options.end()), options.end());
  set<int> nxt;
  nxt.insert(0);
  for(int i = 0; i < 67000; i++) {
    int pre = *nxt.begin();
    nxt.erase(pre);
    for(int j = 0; j < (int) options.size(); j++) {
      if(pre + options[j] < 67000) {
        cando[pre + options[j]] = 1;
        nxt.insert(pre + options[j]);
      }
    }
  }
  for(int i = 67000 - 1; i >= 0; i--) {
    if(!cando[i]) {
      if(i > 66000) fout << 0 << endl;
      else fout << i << endl;
      break;
    }
  }

  return 0;
}
