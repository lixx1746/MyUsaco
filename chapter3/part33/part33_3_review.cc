/*
ID: Zhi Li
PROG: camelot
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int nrow, ncol;
const int MAXR = 40, MAXC = 26;
int dist[MAXC][MAXR][2], cost[MAXC][MAXR], kingcost[MAXC][MAXR];
int kdist[MAXC][MAXR];
const int dy[8] = {-2, -2, -1, -1, +1, +1, +2, +2}, dx[8] = {-1, +1, -2, +2, -2, +2, -1, +1};
const int inf = 10050;

int trans(int x, int y, int kflag) {
  int f = 0;
  int d = dist[x][y][kflag];
  for(int dir = 0; dir < 8; dir++) {
    int newx = x + dx[dir], newy = y + dy[dir];
    if(newx < 0 || newx >= ncol || newy < 0 || newy >= nrow) continue;
    if(dist[newx][newy][kflag] > d + 1) {
      dist[newx][newy][kflag] = d + 1;
      f = 1;
    }
  }
  if(kflag == 0 && dist[x][y][1] > d + kdist[x][y]) {
    dist[x][y][1] = d + kdist[x][y];
    f =  max(f, kdist[x][y]);
  }
  return f;
}

void calc_dist(int col, int row) {
  for(int c = 0; c < ncol; c++)
    for(int r = 0; r < nrow; r++)
      dist[c][r][0] = dist[c][r][1] = inf;
  dist[col][row][0] = 0;
  int f;
  int max_d = dist[col][row][1] = kdist[col][row];
  for(int d = 0; d <= max_d; d++) {
    for(int c = 0; c < ncol; c++) {
      for(int r = 0; r < nrow; r++) {
        if(dist[c][r][0] == d) {
          f = trans(c, r, 0);
          max_d = max(f + d, max_d);
        }
        if(dist[c][r][1] == d) {
          f = trans(c, r, 1);
          max_d = max(max_d, d + f);
        }
      }
    }
  }
}

int main(void) {
  char t[10];
  int pr, pc;

  FILE *fin = fopen("camelot.in", "r");
  FILE *fout = fopen("camelot.out", "w");

  fscanf (fin, "%d %d", &nrow, &ncol);
  fscanf (fin, "%s %d", t, &pr);
  pc = t[0] - 'A'; pr--;

  for (int c = 0; c < ncol; c++)
    for (int r = 0; r < nrow; r++)
      kingcost[c][r] = kdist[c][r] = max(abs(pc - c), abs(pr - r));


  while (fscanf (fin, "%s %d", t, &pr) == 2) {
    pc = t[0] - 'A';
    pr--;
    calc_dist(pc, pr);

    for (int c = 0; c < ncol; c++)
      for (int r = 0; r < nrow; r++) {
        cost[c][r] += dist[c][r][0];
        if (dist[c][r][1] - dist[c][r][0] < kingcost[c][r]) {
          kingcost[c][r] = dist[c][r][1] - dist[c][r][0];
        }
      }
  }

  pc = cost[0][0] + kingcost[0][0];
  for (int c = 0; c < ncol; c++)
    for (int r = 0; r < nrow; r++)
      if (cost[c][r] + kingcost[c][r] < pc) /* better square? */
        pc = cost[c][r] + kingcost[c][r];

  fprintf (fout, "%i\n", pc);
  return 0;
}
