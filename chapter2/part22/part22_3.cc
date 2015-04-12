/*
ID: Zhi Li
PROG: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

long long M;
int N;
int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool used[10];

vector<int> fact(long long a) {
  vector<int> d;
  while(a > 0) {
    d.push_back(a % 10);
    a /= 10;
  }
  reverse(d.begin(), d.end());
  return d;
}

bool isRunRound(vector<int> d) {
  int len = d.size();
  vector<bool> visited(len, false);
  int cnt = 0, pos = 0;
  visited[0] = true;
  while(cnt < len) {
    pos = (pos + d[pos]) % len;
    cnt++;
    if(visited[pos]) break;
    visited[pos] = true;
  }
  return pos == 0 && cnt == len;
}

long long trans(vector<int> a) {
  long long ans = 0;
  for(int i = 0; i < (int) a.size(); i++) {
    ans = 10 * ans + a[i];
  }
  return ans;
}

bool gen(const int& num, vector<int>& sol) {
  if((int) sol.size() == num && trans(sol) > M && isRunRound(sol)) return true;
  for(int i = 1; i <= 9; i++) {
    if(!used[i]) {
      used[i] = 1;
      sol.push_back(data[i]);
      if(gen(num, sol)) return true;
      sol.pop_back();
      used[i] = 0;
    }
  }
  return false;
}

int main(void) {
  ifstream fin ("runround.in");
  ofstream fout ("runround.out");
  fin >> M;
  vector<int> d = fact(M);
  int num = d.size();
  vector<int> sol;
  for(int i = num; i <= 9; i++) {
    sol.clear();
    memset(used, 0, sizeof used);
    if(gen(i, sol)) break;
  }
  fout << trans(sol) << endl;
  return 0;
}
