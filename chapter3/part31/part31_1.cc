/*
ID: Zhi Li
PROG: agrinet
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
int N;
int graph[105][105];
bool intree[105];
int source[105], dist[105];
const int inf = 987654321;

int main(void) {
  ifstream fin ("agrinet.in");
  ofstream fout ("agrinet.out");
  fin >> N;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      fin >> graph[i][j];

  for(int i = 1; i <= N; i++) {
    source[i] = -1;
    dist[i] = inf;
  }

  int treesize = 1, treecost = 0;
  intree[1] = 1;

  for(int j = 2; j <= N; j++) {
    dist[j] = graph[1][j];
    source[j] = 1;
  }

  while(treesize < N) {
    int dis = inf, i = -1;
    for(int j = 1; j <= N; j++) {
      if(!intree[j] && dis > dist[j]) {
        dis = dist[j];
        i = j;
      }
    }

    treesize++;
    treecost += dist[i];
    intree[i] = 1;

    for(int j = 1; j <= N; j++) {
      if(!intree[j] && dist[j] > graph[i][j]) {
        dist[j] = graph[i][j];
        source[j] = i;
      }
    }
  }

  fout << treecost << endl;


  return 0;
}
