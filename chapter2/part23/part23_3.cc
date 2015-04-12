/*
ID: Zhi Li
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int ans[10];
int trans[4] = { 0 ,  1,   2,   3 }; // 1 means +, 2 means -, 3 means " "
char mp[4]   = {'?', '+', '-', ' '};

vector<string> res;

void print(void) {
  string a = "";
  for(int i = 1; i <= N; i++) {
    a.push_back(i + '0');
    if(i < N) a.push_back(mp[ans[i]]);
  }
  res.push_back(a);
}


int ans_to_int() {
  vector<int> st;
  int num = 0;
  for(int i = 1; i <= N; i++) {
    num = 10 * num + i;
    if(ans[i] != 3) { st.push_back(num); num = 0; }
  }
  reverse(st.begin(), st.end());
  for(int i = 1; i < N; i++) {
    if(ans[i] != 3) {
      int top1 = st.back(); st.pop_back();
      int top2 = st.back(); st.pop_back();
      if(ans[i] == 2) {
        st.push_back(top1 - top2);
      }
      else if(ans[i] == 1) st.push_back(top2 + top1);
    }
  }
  return st.back();
}


void solve(void) {
  int i;
  for(i = 1; i < N; i++) if(!ans[i]) break;
  if(i >= N) {
    if(ans_to_int() == 0) print();
    return;
  }
  for(int j = 1; j <= 3; j++) {
    ans[i] = j;
    solve();
    ans[i] = 0;
  }
}

int main(void) {
  ifstream fin ("zerosum.in");
  ofstream fout ("zerosum.out");
  fin >> N;
  solve();
  sort(res.begin(), res.end());
  for(int i = 0; i < (int) res.size(); i++) fout << res[i] << endl;
  return 0;
}
