/*
ID: Zhi Li
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

char mp[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool isPal(string s) {
  int l = 0, r = s.size() - 1;
  while(l <= r) {
    if(s[l++] != s[r--]) return 0;
  }
  return 1;
}
string base10ToB(int n, int b) {
  vector<int> st;
  while(n >= b) {
    st.push_back(n % b);
    n /= b;
  }
  string ans(1, mp[n]);
  while(!st.empty()) {
    int ele = st.back();
    st.pop_back();
    ans += mp[ele];
  }
  return ans;
}

int main(void) {
  ifstream fin ("dualpal.in");
  ofstream fout ("dualpal.out");
  int S, N;
  fin >> N >> S;
  for(int num = S + 1, i = 0; i < N; num++) {
    int c = 0;
    for(int b = 2; c < 2 && b <= 10; b++) {
      if(isPal(base10ToB(num, b))) c++;
    }
    if(c == 2) {
     i++;
     fout << num << endl;
    }
  }
  return 0;
}
