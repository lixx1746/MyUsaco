/*
ID: Zhi Li
PROG: sprime
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

int N;

bool isPrime(int num) {
  if(num <= 3) return num >= 2;
  if((num & 1) == 0 || num % 3 == 0) return 0;
  for(int i = 5; i < sqrt(num) + 1; i += 6) {
    if(num % i == 0 || num % (i + 2) == 0) return 0;
  }
  return 1;
}
int count(int a) {
  int ans = 0;
  while(a > 0) {
    ans++;
    a /= 10;
  }
  return ans;
}

int pow(int a, int p) {
  int t = a;
  for(int i = 1; i < p; i++) t *= a;
  return t;
}
int prime[] = {2, 3, 5, 7};
int odd[] = {1, 3, 5, 7, 9};

void solve(int n, int pos, int sol, vector<int>& res) {
  if(pos == n) {
    if(count(sol) == n && isPrime(sol)) res.push_back(sol);
    return;
  }
  for(int i = pos; i < n; i++) {
    if(i == 0)
      for(int j = 0; j < 4; j++) solve(n, i + 1, 10 * sol + prime[j], res);
    else {
      for(int k = 0; k < 5; k ++) {
        int tmp =  10 * sol + odd[k];
        if(isPrime(tmp)) solve(n, i + 1, tmp, res);
      }
    }
  }
}

int main(void) {
  ifstream fin ("sprime.in");
  ofstream fout ("sprime.out");
  fin >> N;
  vector<int> res;
  solve(N, 0, 0, res);
  for(int i = 0; i < (int) res.size(); i++) fout << res[i] << endl;
  return 0;
}
