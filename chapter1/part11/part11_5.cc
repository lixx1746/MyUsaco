/*
ID: Zhi Li
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  ifstream fin ("beads.in");
  ofstream fout ("beads.out");
  string str;
  char cl, cr;
  int no;
  fin >> no >> str;
  str += str;
  int n = str.size(), ans = 1;
  for(int i = 1; i < n; i++) {
    int l = i - 1, r = i;
    while(l >= 0 && ((cl = str[l]) == 'w')) l--;
    while(r < n && ((cr = str[r]) == 'w')) r++;
    while(l >= 0 && (cl == str[l] || str[l] == 'w')) l--;
    while(r < n && (cr == str[r] || str[r] == 'w')) r++;
    ans = min(n / 2, max(ans, r - l - 1));
  }
  fout << ans << endl;
  return 0;
}
