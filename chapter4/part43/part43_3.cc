/*
ID: Zhi Li
PROG: lgame
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
set<string> dict;
typedef pair<string, string> Pss;
map<int, set<Pss> > res;
int char_to_int[] = { 2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5,
                      2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7 };

string str;
int ans, used[8];
int comp(string a, string b) {
  for(int i = 0; i < (int) min(a.size(), b.size()); i++) {
    if(a[i] > b[i]) return 1;
    else if(a[i] < b[i]) return -1;
  }
  if(a.size() > b.size()) return 1;
  else if(a.size() < b.size()) return -1;
  return 0;
}

inline int cacl(string s) {
  int ans = 0;
  for(int i = 0; i < (int) s.size(); i++) ans += char_to_int[s[i] - 'a'];
  return ans;
}

void solve(string& s, const int len) {
  if((int) s.size() == len) {
    for(int j = 1; j <= len; j++) {
      int flag1 = 0, flag2 = 0, tmp = 0;
      string left = s.substr(0, j);
      string right = s.substr(j, len - j);
      if(dict.count(left)) flag1 = 1;
      if(dict.count(right)) flag2 = 1;
      tmp += (flag1 ? cacl(left) : 0) + (flag2 ? cacl(right) : 0);
      ans = max(ans, tmp);
      if(!flag1 && !flag2) continue;
      else if(!flag1) {left = right; right = ""; }
      else if(!flag2) right = "";
      else if(comp(left, right) > 0) swap(left, right);
      res[tmp].insert(make_pair(left, right));
    }
    return;
  }
  for(int k = 0; k < (int) str.size(); k++) {
    if(!used[k]) {
      used[k] = 1;
      int l = s.size();
      s.push_back(str[k]);
      solve(s, len);
      s.resize(l);
      used[k] = 0;
    }
  }
}

int main(void) {
  ifstream fin ("lgame.in");
  ofstream fout ("lgame.out");
  ifstream fin_dict ("lgame.dict");
  string line;
  while(true) {
    fin_dict >> line;
    if(line == ".") break;
    dict.insert(line);
  }
  fin >> str;
  int len = str.size();
  string s;
  for(int i = 1; i <= len; i++) {
    memset(used, 0, sizeof used);
    solve(s, i);
  }
  fout << ans << endl;
  set<Pss>::iterator it = res[ans].begin();
  for(; it != res[ans].end(); it++) {
    if((*it).second != "") fout << (*it).first << " " << (*it).second << endl;
    else fout << (*it).first << endl;
  }
  return 0;
}
