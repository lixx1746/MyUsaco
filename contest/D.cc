#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

long long N, A, B;
pair<long long, long long> data[50005];

int main(void) {
  ifstream fin("12.in");
  ofstream fout("12.out");
  fin >> N >> A >> B;
  string str;
  long long w;
  for(int i = 0; i < N; i++) {
    fin >> str >> w;
    long long state = str == "NS" ? 0 : 1;
    data[i] = make_pair(w, state);
  }
  sort(data, data + N);
  int i = 0, j = N;
  while(i < N && data[i].first < A) i++;
  long long state = data[i].second;
  long long ans = 0;
  if(state == 1) ans += data[i].first - A + 1;
  else if(i > 0 && data[i-1].second == 1) ans += max((data[i].first + data[i - 1].first) / 2LL - A + 1, 0LL);
  while(j > i && data[j - 1].first > B) j--;
  if(data[j - 1].second == 1) ans += B - data[j - 1].first;
  else if(j < N && data[j].second == 1) ans += max(0LL, B - (data[j - 1].first + data[j].first + 1) / 2LL + 1);
  i++;
  for(; i < j; i++) {
    if(data[i].second == 1LL) {
      if(state == 0) ans += data[i].first - ((data[i].first + data[i - 1].first + 1) / 2LL) + 1;
      else ans += data[i].first - data[i - 1].first;
      state = 1;
    }
    else {
      if(state == 1) {
        ans += ((data[i].first + data[i - 1].first) / 2LL) - data[i - 1].first;
      }
      state = 0;
    }
  }
  fout << ans << endl;
  return 0;
}
