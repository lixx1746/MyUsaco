/*
ID: Zhi Li
PROG: sort3
LANG: C++
*/


#include <fstream>

using namespace std;

int N;
int data[1010];
int sta[4], acc[4];


int main(void) {
  ifstream fin ("sort3.in");
  ofstream fout ("sort3.out");
  fin >> N;
  for(int i = 0; i < N; i++) { fin >> data[i]; sta[data[i]]++; }
  for(int i = 1; i < 4; i++) acc[i] = acc[i - 1] + sta[i];
  int res = 0;
  for(int ele = 1; ele < 3; ele++) {
    int cnt = 0;
    for(int i = acc[ele - 1]; i < N && cnt < sta[ele]; i++, cnt++) {
      if(data[i] != ele) {
        int flag = 0;
        for(int j = acc[data[i] - 1]; j < N; j++) {
          if(data[j] == ele) {
            swap(data[i], data[j]);
            flag = 1;
            res++;
            break;
          }
        }
        if(!flag) {
          for(int j = acc[ele]; j < N; j++) {
            if(data[j] == ele) {
              swap(data[i], data[j]);
              res++;
              break;
            }
          }
        }
      }
    }
  }
  fout << res << endl;
  return 0;
}
