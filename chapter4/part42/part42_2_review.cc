/*
ID: Zhi Li
PROG: job
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int N, M1, M2;

int time_A[35], left_A[35];
int time_B[35], left_B[35];
int job_A[1010], job_B[1010];

int main(void) {
  ifstream fin ("job.in");
  ofstream fout ("job.out");

  fin >> N >> M1 >> M2;
  for(int i = 0; i < M1; i++) fin >> time_A[i];
  for(int i = 0; i < M2; i++) fin >> time_B[i];
  int ans1 = 0, ans2 = 0;
  for(int i = 0; i < N; i++) {
    int min1, id = -1;
    for(int j = 0; j < M1; j++) {
      if(id == -1 || min1 > left_A[j] + time_A[j]) {
        id = j;
        min1 = left_A[j] + time_A[j];
      }
    }
    job_A[i] = min1;
    left_A[id] = min1;
    ans1 = max(ans1, left_A[id]);
    int min2, id2 = -1;
    for(int j = 0; j < M2; j++) {
      if(id2 == -1 || min2 > left_B[j] + time_B[j]) {
        id2 = j;
        min2 =  left_B[j] + time_B[j];
      }
    }
    job_B[i] = min2;
    left_B[id2] = min2;
  }

  for(int i = 0; i < N; i++) {
    ans2 = max(ans2, job_A[i] + job_B[N - i - 1]);
  }


  fout << ans1 << " " << ans2 << endl;

  return 0;
}
