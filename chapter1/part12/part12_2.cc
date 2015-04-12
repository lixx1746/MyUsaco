/*
ID: Zhi Li
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> rot90(vector<string> img) {
  int n = img.size();
  vector<string> res(n, string(n, ' '));
  for(int i = 0 ; i < n; i++)
    for(int j = 0; j < n; j++)
      res[j][n - i - 1] = img[i][j];
  return res;
}

vector<string> rot(vector<string> img, int k) {
  for(int i = 1; i <= k; i++) img = rot90(img);
  return img;
}

vector<string> refle(vector<string> img) {
  int n = img.size();
  vector<string> res(n, string(n, ' '));
  for(int i = 0 ; i < n; i++)
    for(int j = 0; j < n; j++)
      res[i][n - j - 1] = img[i][j];
  return res;
}

bool is_equal(vector<string> a, vector<string> b) {
  int n = a.size();
  for(int i = 0;i < n; i++)
    for(int j = 0; j < n; j++)
      if(a[i][j] != b[i][j]) return false;
  return true;
}

int main(void) {
  ifstream fin ("transform.in");
  ofstream fout ("transform.out");
  int N;
  string str;
  vector<string> img, to_img;
  fin >> N;
  for(int i = 0; i < 2 * N; i++) {
    fin >> str;
    if(i < N) img.push_back(str);
    else to_img.push_back(str);
  }

  return 0;
}
