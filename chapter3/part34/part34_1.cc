/*
ID: Zhi Li
PROG: heritage
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

string inorder, preorder;

string post(int il, int ir, int pl, int pr) {
  if(il >= ir || pl >= pr) return "";
  string res = "";
  char root = preorder[pl];
  cout << root << endl;
  for(int j = il; j < ir; j++) {
    if(inorder[j] == root) {
      string hl = post(il,     j,     pl + 1,       pl + j - il + 1);
      string hr = post(j + 1, ir,   pl + j - il + 1,          pr   );
      res = res + hl + hr;
      res.push_back(root);
      break;
    }
  }
  return res;
}

int main(void) {
  ifstream fin ("heritage.in");
  ofstream fout ("heritage.out");
  fin >> inorder >> preorder;
  int n = inorder.size();
  fout << post(0, n, 0, n) << endl;
  return 0;
}
