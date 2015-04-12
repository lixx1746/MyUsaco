/*
ID: Zhi Li
PROG: contact
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
int A, B, N;
int cnt[20000];
vector<string> sta[20000];
set<int> mask;

void go(int node, string path) {
  if(cnt[node] == 0) return;
  if(node & 1) path.push_back('0');
  else path.push_back('1');
  if((int)path.size() > B) return;
  else if((int) path.size() >= A && (int) path.size() <= B) {
    sta[cnt[node]].push_back(path);
    mask.insert(cnt[node]);
  }
  go(2 * node + 1, path);
  go(2 * node + 2, path);
}
bool mycomp(string a, string b) {
  if(a.size() < b.size()) return 1;
  return a < b;
}

int main(void) {
  ifstream fin ("contact.in");
  ofstream fout ("contact.out");
  fin >> A >> B >> N;
  string str, line;
  while(fin >> line) str += line;
  int len = str.size();
  for(int i = 0; i < len; i++) {
    int node = 0;
    for(int j = 0; j < B && i + j < len; j++) {
      char c = str[i + j];
      if(c == '0') {
        node = 2 * node + 1;
        cnt[node]++;
      }
      else {
        node = 2 * node + 2;
        cnt[node]++;
      }
    }
  }

  go(1, ""); go(2, "");

  set<int>::reverse_iterator rit = mask.rbegin();
  for(int i = 0; i < N && rit != mask.rend(); rit++, i++) {
    vector<string> res = sta[*rit];
    sort(res.begin(), res.end(), mycomp);
    fout << *rit << endl;
    for(int i = 0; i < (int) res.size(); i++) {
      if(i != 0 && i % 6 == 0)  fout << endl;
      if(i % 6 != 0) fout << " ";
      fout << res[i];
    }
    fout << endl;
  }

  return 0;
}
