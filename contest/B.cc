#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int N, M;
char G[55][55];

inline bool check(int i, int j) {
  if(G[i][j] == '.') {
    if(i == 0 || (i - 1 >= 0 && G[i - 1][j] == '#'))
      if(i + 2 < N) {
        if(G[i + 1][j] == '.' && G[i + 2][j] == '.') return 1;
      }

    if(j == 0 || (j - 1 >= 0 && G[i][j - 1] == '#'))
      if(j + 2 < M) {
        if(G[i][j + 1] == '.' && G[i][j + 2] == '.') return 1;
      }
  }
    return 0;
}

int main(void) {
  ifstream fin("crosswords.in");
  ofstream fout("crosswords.out");
  fin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      fin >> G[i][j];

  vector<pair<int, int> > res;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(check(i, j)) res.push_back(make_pair(i + 1, j + 1));
    }
  }

  fout << res.size() << endl;
  for(int i = 0; i < (int) res.size(); i++) {
    fout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
