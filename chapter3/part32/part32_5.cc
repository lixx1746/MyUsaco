/*
ID: Zhi Li
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

set<string> visited;

typedef struct state {
  string str;
  vector<int> path;
} State;

char mp[] = { 'A', 'B', 'C' };

string trans(string sta, int w) {
  string res;
  if(w == 0) {
    string l = sta.substr(4, 4), r = sta.substr(0, 4);
    reverse(l.begin(), l.end()); reverse(r.begin(), r.end());
    res = l + r;
  }
  if(w == 1) {
    string u = sta.substr(0, 4), l = sta.substr(4, 4);
    reverse(l.begin(), l.end());
    for(int i = 3; i > 0; i--) {
      l[i] = l[i - 1]; u[i] = u[i - 1];
    }
    l[0] = sta[4]; u[0] = sta[3];
    reverse(l.begin(), l.end());
    res = u + l;
  }
  if(w == 2) {
    string u = sta.substr(0, 4), l = sta.substr(4, 4);
    reverse(l.begin(), l.end());
    l[2] = u[2]; u[2] = u[1]; u[1] = l[1]; l[1] = sta[5];
    reverse(l.begin(), l.end());
    res = u + l;
  }
  return res;
}

int main(void) {
  ifstream fin ("msquare.in");
  ofstream fout ("msquare.out");
  string goal;
  char c;
  for(int i = 0; i < 8; i++) { fin >> c; goal.push_back(c); }
  queue<State> q;
  State init = { "12345678", vector<int> () };
  visited.insert("12345678");
  q.push(State(init));
  while(!q.empty()) {
    State state = q.front();
    q.pop();
    if(state.str == goal) {
      fout << state.path.size() << endl;
      for(int i = 0; i < (int) state.path.size(); i++) {
        if(i != 0 && i % 60 == 0) fout << endl;
        fout << mp[state.path[i]];
      }
      fout << endl;
      break;
    }
    for(int i = 0; i < 3; i++) {
      string s = state.str;
      string sto = trans(s, i);
      if(visited.count(sto) == 0) {
        visited.insert(sto);
        vector<int> path = state.path;
        path.push_back(i);
        State to = { sto, path };
        q.push(to);
      }
    }
  }


  return 0;
}
