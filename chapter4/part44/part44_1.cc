/*
ID: Zhi Li
PROG: shuttle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>

using namespace std;
typedef struct { string state; int space; int len;  vector<int> path; } State;
struct comp {
  bool operator() (State a, State b) { if(a.len > b.len) return 1; return 0; }
};
int dir[] = {-1, -2, 1, 2};
set<string> visited;
int N;
inline bool check(State from, int to, int d) {
  bool res = 0;
  if(d == 1 && from.state[to] == from.state[to + 1]) res = 1;
  if(d == 3 && from.state[to] == from.state[to - 1]) res = 1;
  if((d == 0 || d == 1) && from.state[to] == 'B') res = 1;
  if((d == 2 || d == 3) && from.state[to] == 'W') res = 1;
  return res;
}

int main(void) {
  ifstream fin ("shuttle.in");
  ofstream fout ("shuttle.out");
  fin >> N;
  State goal =  { string(N, 'B') + " " + string(N, 'W'), N,  987654321, vector<int> () };
  queue<State> pq;
  string init = string(N, 'W') + " " + string(N, 'B');
  pq.push((State) {init, N, 0, vector<int> () });
  while(!pq.empty()) {
    State from = pq.front();
    visited.insert(from.state);
    pq.pop();
    if(from.len > goal.len) break;
    int space_pos = from.space;
    for(int d = 0; d < 4; d++) {
      int to = space_pos + dir[d];
      if(to >= 0 && to < (int) from.state.size()) {
        if(check(from, to, d)) continue;
        string to_state = from.state;
        swap(to_state[to], to_state[space_pos]);
        if(visited.count(to_state)) continue;
        visited.insert(to_state);
        vector<int> new_path = from.path;
        new_path.push_back(to + 1);
        State new_state =  {to_state, to, from.len + 1, new_path};
        if(new_state.state == goal.state && new_state.len <= goal.len) {
          goal.len = min(goal.len, new_state.len);
          if(goal.path.empty() || new_state.len < goal.len) goal.path = new_state.path;
          else if(new_state.len == goal.len) {
            int flag = 0;
            for(int i = 0; !flag && i < new_state.len; i++) {
              cout << "hee" << endl;
              if(goal.path[i] > new_state.path[i]) flag = 1;
            }
            if(flag) goal.path = new_state.path;
          }
          continue;
        }
        pq.push(new_state);
      }
    }
  }

  for(int i = 0; i < goal.len; i++) {
    if(i != 0 && i % 20 == 0) fout << endl;
    if(i % 20 != 0) fout << " ";
    fout << goal.path[i];
  }
  fout << endl;
  return 0;
}
