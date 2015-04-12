/*
ID: Zhi Li
PROG: ttwo
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

const int inf = 98765432;

int dp[10][10][10][10][4][4];
int visited[10][10][10][10][4][4];
char data[10][10];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int fnew_x, fnew_y, fnew_dir, cnew_x, cnew_y, cnew_dir;

void trans(int x, int y, int dir, int& new_x, int& new_y, int& new_dir) {
  int tempx = x + dx[dir], tempy = y + dy[dir];
  if(tempx >= 0 && tempx < 10 && tempy >= 0 && tempy < 10 && data[tempy][tempx] != '*') {
    new_x = tempx; new_y = tempy; new_dir = dir;
  }
  else {
    new_x = x; new_y = y; new_dir = (dir + 1) % 4;
  }
}

int go(int fx, int fy, int cx, int cy, int df, int dc) {
  int& res = dp[fx][fy][cx][cy][df][dc];
  visited[fx][fy][cx][cy][df][dc]++;
  if(visited[fx][fy][cx][cy][df][dc] >= 2) return res = inf;
  if(res != -1) return res;
  if(fx == cx && fy == cy) return res = 0;
  trans(fx, fy, df, fnew_x, fnew_y, fnew_dir);
  trans(cx, cy, dc, cnew_x, cnew_y, cnew_dir);
  return res = 1 + go(fnew_x, fnew_y, cnew_x, cnew_y, fnew_dir, cnew_dir);
}

int main(void) {
  ifstream fin ("ttwo.in");
  ofstream fout ("ttwo.out");
  char c;
  int fx, fy, cx, cy;
  for(int i = 9; i >= 0; i--) {
    for(int j = 0; j < 10; j++) {
      fin >> c;
      data[i][j] = c;
      if(c == 'F') {
        fx = j; fy = i;
      }
      if(c == 'C') {
        cx = j; cy = i;
      }
    }
  }
  memset(dp, -1, sizeof dp);
  int res = go(fx, fy, cx, cy, 0, 0);
  if(res >= inf) fout << 0 << endl;
  else fout << res << endl;

  return 0;
}
