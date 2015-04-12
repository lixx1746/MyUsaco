/*
ID: Zhi Li
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, m, p;
double eps = 0.00000001;
int line2(int x);

int line1(int x) {
  if(n == 0) return line2(x);
  double k = 1.0 * m / n;
  int top = floor(k * x);
  int res = 0;
  res = top;
  if(res >= 1 && abs(1.0 * k * x - 1.0 * top) < eps && top >= 1) res--;
  return res;
}
int line2(int x) {
  if(n == p) return line1(x);
  double k = 1.0 * m / (n - p), d = 1.0 * p * k;
  int top = floor(k * x - d);
  int res;
  res = top;
  if(res >= 1 && abs(1.0 * k * x - d - 1.0 * top) < eps && top >= 1) res--;
  return res;
}

int line3(int x) {
  double k1 = 1.0 * m / n, k2 =  1.0 * m / (n - p), d = 1.0 * p * k2;
  int top = floor(k1 * x), bottom = ceil(k2 * x - d);
  int res = top - bottom + 1;
  if(res >= 1 && abs(top - k1 * x) < eps) res--;
  if(res >= 1 && abs(k2 * x - d- bottom) < eps) res--;
  return res;
}

int main(void) {
  ifstream fin ("fence9.in");
  ofstream fout ("fence9.out");
  fin >> n >> m >> p;
  int ans = 0;
  if(n <= p) {
    if(n == p) for(int x = 1; x < n; x++) ans += line1(x);
    else {
      for(int x = 1; x <= n; x++) ans += line1(x);
      for(int x = n + 1; x < p; x++) ans += line2(x);
    }
  }
  else {
    for(int x = 1; x <= p; x++) ans += line1(x);
    for(int x = p + 1; x < n; x++) ans += line3(x);
  }


  fout << ans << endl;

  return 0;
}
