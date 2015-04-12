#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_N = 100005;
int N;
int x[MAX_N], y[MAX_N];

int main(void) {
  ifstream fin("marathon.in");
  ofstream fout("marathon.out");
  fin >> N;
  long long acc = 0;
  int x0, y0;
  fin >> x0 >> y0;
  for(int i = 1; i< N; i++) {
    fin >> x[i] >> y[i];
    acc += abs(x[i] - x0) + abs(y[i] - y0);
    x0 = x[i]; y0 = y[i];
  }
  long long ans = acc;
  for(int i = 1; i < N - 1; i++) {
    int d = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) + abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
    int delta = abs(abs(x[i - 1] - x[i + 1]) + abs(y[i - 1] - y[i + 1]) - d);
    ans = min(ans, acc - delta);
  }
  fout << ans << endl;
  return 0;
}
