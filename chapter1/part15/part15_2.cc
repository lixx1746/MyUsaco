/*
ID: Zhi Li
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
int a, b;

int rev(int a) {
  int ans = 0;
  while(a > 0) {
    ans = 10 * ans + (a % 10);
    a /= 10;
  }
  return ans;
}
int pow(int a, int p) {
  int t = a;
  for(int i = 1; i < p; i++) t *= a;
  return t;
}

int count(int n) {
  int ans = 0;
  while(n > 0) {
    ans++;
    n /= 10;
  }
  return ans;
}

void gen_Pal(vector<int>& res, const int n, int sol, int pos) {
  if(!(n & 1) && (pos == n / 2)) {
    if(count(sol) != n / 2) return;
    int ans = pow(10, n / 2) * sol + rev(sol);
    res.push_back(ans);
    return;
  }
  if(n % 2 == 1 && pos == n / 2 + 1) {
    if(count(sol) != n / 2 + 1) return;
    int mid = sol % 10;
    int front = sol / 10;
    if(n == 1) res.push_back(mid);
    else {
      int ans = pow(10, n / 2) * sol + rev(front);
      if(count(ans) == n) res.push_back(ans);
    }
    return;
  }
  for(int i = pos; i < n / 2 + (n % 2 != 0); i++) {
    for(int j = 0; j <= 9; j++) {
      if(i == 0 && j % 2 == 0) continue;
      gen_Pal(res, n, 10 * sol + j, i + 1);
    }
  }
}


bool isPrime(int num) {
  if(num <= 3) return num >= 2;
  if((num & 1) == 0 || num % 3 == 0) return 0;
  for(int i = 5; i < sqrt(num) + 1; i += 6) {
    if(num % i == 0 || num % (i + 2) == 0) return 0;
  }
  return 1;
}


int main(void) {
  ifstream fin ("pprime.in");
  ofstream fout ("pprime.out");
  fin >> a >> b;
  int na = count(a), nb = count(b);
  vector<int> cand;
  for(int i = na; i <= nb; i++) gen_Pal(cand, i, 0, 0);
  for(int i = 0; i < (int) cand.size() && cand[i] <= b; i++) {
    if(cand[i] < a) continue;
    if(isPrime(cand[i])) fout << cand[i] << endl;
  }

  return 0;
}
