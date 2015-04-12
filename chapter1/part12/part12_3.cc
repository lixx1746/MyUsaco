/*
ID: Zhi Li
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

char mp[10][3] = { {' ', ' ', ' '}, {' ', ' ', ' '},
                   {'A', 'B', 'C'}, {'D', 'E', 'F'},
                   {'G', 'H', 'I'}, {'J', 'K', 'L'},
                   {'M', 'N', 'O'}, {'P', 'R', 'S'},
                   {'T', 'U', 'V'}, {'W', 'X', 'Y'} };

int main(void) {
  ifstream fin ("namenum.in");
  ofstream fout ("namenum.out");
  ifstream dictin ("dict.txt");
  long long n;
  fin >> n;
  map<char, int> chToNum;
  for(int i = 2; i < 10; i++)
    for(int j = 0; j < 3; j++)
      chToNum[mp[i][j]] = i;
  string str;
  vector<string> res;
  while(dictin >> str) {
    long long num = 0;
    for(int i = 0; i < (int) str.size(); i++) num = 10 * num + chToNum[str[i]];
    if(num == n) res.push_back(str);
  }
  if(res.size() == 0) fout << "NONE" << endl;
  else {
    for(int i = 0; i < (int) res.size(); i++) fout << res[i] << endl;
  }
  return 0;
}
