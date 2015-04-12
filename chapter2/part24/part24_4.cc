/*
ID: Zhi Li
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int P, dis;
char fc, tc;
map<char, int> name_to_num;
map<int, char> num_to_name;
int dist[55][55];
bool mask[55];
const int inf = 1061109567;

int main(void) {
  ifstream fin ("comehome.in");
  ofstream fout ("comehome.out");
  for(char c = 'A'; c <= 'Z'; c++)
    { name_to_num[c] = c - 'A'; num_to_name[c - 'A'] = c; }
  for(char c = 'a'; c <= 'z'; c++)
    { name_to_num[c] = c - 'a' + 26; num_to_name[c - 'a' + 26] = c; }

  memset(dist, 0x3F, sizeof dist);
  fin >> P;
  for(int i = 0; i < P; i++) {
    fin >> fc >> tc >> dis;
    int from = name_to_num[fc], to = name_to_num[tc];
    dist[from][to] = min(dist[from][to], dis);
    dist[to][from] = dist[from][to];
    dist[to][to] = dist[from][from] = 0;
    mask[from] = mask[to] = 1;
  }

  for(int k = 0; k < 55; k++) if(mask[k]) {
      for(int i = 0; i < 55; i++) if(mask[i]) {
          for(int j = 0; j < 55; j++) if(mask[j]) {
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

  int dis = inf, ans = -1;
  for(int i = 0; i < 25; i++) {
    if(dis > dist[25][i]) {
      ans = i;
      dis = dist[25][i];
    }
  }

  fout << num_to_name[ans] << " " << dis << endl;

  return 0;
}
