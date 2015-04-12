/*
ID: Zhi Li
PROG: fracdec
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
int N, D, cnt;
map<int, int> visited;
//vector<int> frac;

string int_to_string(int a) {
  if(a == 0) return "0";
  string res;
  while(a > 0) {
    res.push_back(a % 10 + '0');
    a /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main(void) {
  ifstream fin ("fracdec.in");
  ofstream fout ("fracdec.out");
  fin >> N >> D;
  int dec = N / D;
  string res = int_to_string(dec);
  res.push_back('.');
  if(N % D == 0) res.push_back('0');
  else {
    int r = 10 * (N % D);
    string frac;
    for(int i = 0; ;r *= 10) {
      if(visited.count(r) || r == 0) {
        if(r == 0) res += frac;
        else  {
          int id = visited[r];
          frac.insert(id, 1, '(');
          frac.push_back(')');
          res += frac;
        }
        break;
      }
      visited[r] = i++;
      int d = r / D;
      r %= D;
      frac += int_to_string(d);
    }
  }


  for(int i = 0; i < (int) res.size(); i++) {
    if(i > 0 && i % 76 == 0) fout << endl;
    fout << res[i];
  }
  fout << endl;

  return 0;
}
