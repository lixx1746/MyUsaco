#include <fstream>
#include <iostream>

using namespace std;
int speed[100005];
int N;
int main(void) {
  ifstream fin("cowjog.in");
  ofstream fout("cowjog.out");
  fin >> N;
  int u;
  for(int i = 0; i < N; i++) {
    fin >> u >> speed[i];
  }
  int pre = speed[N - 1], ans = 1;
  for(int i = N - 2; i >= 0; i--) {
    //cout << pre << endl;
    if(pre >= speed[i]) {
      ans++;
      pre = speed[i];
    }
  }
  fout << ans << endl;
  return 0;
}
