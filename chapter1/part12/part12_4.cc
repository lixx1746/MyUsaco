/*
ID: Zhi Li
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

char mp[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
               'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'
};

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
  ifstream fin ("palsquare.in");
  ofstream fout ("palsquare.out");
  int B;
  fin >> B;
  for(int i = 1; i <= 300; i++) {
    string tmp = base10ToB(i * i, B);
    if(isPal(tmp)) fout << base10ToB(i, B) << " " << tmp << endl;
  }
  return 0;
}
