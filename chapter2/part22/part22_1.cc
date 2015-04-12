/*
ID: Zhi Li
PROG: preface
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

int nu[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string s[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
char st[] = {'I', 'V', 'X', 'L', 'C', 'D','M'};

map<char, int> cnt;

int main(void) {
  ifstream fin ("preface.in");
  ofstream fout ("preface.out");
  fin >> N;
  for(int j = 1; j <= N; j++) {
    string ans;
    int num = j;
    for(int i = 0; i < 13; i++) {
      if(num >= nu[i]) {
        for(int j = 0; j < num / nu[i]; j++) ans += s[i];
        num -= (num / nu[i]) * nu[i];
      }
    }
    for(int i = 0; i < (int) ans.size(); i++) cnt[ans[i]]++;
  }
  for(int i = 0; i < 7; i++) {
    if(cnt.count(st[i])) fout << st[i] << " " << cnt[st[i]] << endl;
  }

  return 0;
}
