/*
ID: Zhi Li
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int ans[7];
int leap_year[13], non_leap_year[13];

inline int is_leap(int y) {
  if(y % 400 == 0) return 1;
  else if(y % 4 == 0 && (y % 100 != 0)) return 1;
  else return 0;
}

int main(void) {
  ifstream fin ("friday.in");
  ofstream fout ("friday.out");
  int N;
  fin >> N;
  for(int i = 1; i <= 12; i++) {
    non_leap_year[i] = non_leap_year[i  - 1] + month[i - 1];
    leap_year[i] = non_leap_year[i];
    if(i >= 2) leap_year[i]++;
  }
  int delta = 0, *p;
  for(int i = 1; i <= N; i++) {
    p = non_leap_year;
    if(is_leap(1900 + i - 1)) p = leap_year;
    for(int j = 0; j < 12; j++) {
      int date = *(p + j) + 13 + delta;
      int k = date % 7;
      ans[k]++;
    }
    if(is_leap(1900 + i - 1)) delta += 366;
    else delta += 365;
  }
  fout << ans[6] << " ";
  for(int i = 0; i < 6; i++) {
    if(i > 0) fout << " ";
    fout << ans[i];
  }
  fout << endl;
  return 0;
}
