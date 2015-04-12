/*
ID: Zhi Li
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int init[15], rec[15];
string name[15];
map<string, int> name_to_id;

int main(void) {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");
  int n, total, c;
  string str;
  fin >> n;
  for(int i = 0; i < n; i++) {
    fin >> str;
    name[i] = str;
    name_to_id[str] = i;
  }
  while(fin >> str) {
    fin >> total >> c;
    int val = (c == 0 ? 0 : total / c);
    init[name_to_id[str]] = c * val;
    for(int i = 0; i < c; i++) {
      fin >> str;
      rec[name_to_id[str]] += val;
    }
  }
  for(int i = 0; i < n; i++)
    fout << name[i] << " " << rec[i] - init[i] << endl;

  return 0;
}
