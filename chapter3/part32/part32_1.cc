/*
ID: Zhi Li
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;

int get(int a) {
  vector<int> res;
  for(int i = 0;i < 4; i++) {
    res.push_back(a % 10);
    a /= 10;
  }
  int ans  = 0;
  for(int i = 3; i >= 0; i--) {
    ans = 10 * ans + res[i];
  }
  return ans;
}

int main(void) {
  ifstream fin ("fact4.in");
  ofstream fout ("fact4.out");
  fin >> N;
  int ans = 1;
  for(int i = 1; i <= N; i++) {
    ans *= i;
    while(ans % 10 == 0) ans /= 10;
    ans = get(ans);
  }

  fout << ans % 10 << endl;

  return 0;
}
