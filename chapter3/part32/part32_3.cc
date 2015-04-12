/*
ID: Zhi Li
PROG: spin
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

const int TimeLimits = 360;
typedef struct wheel {
  int speed, num;
  int start[5];
  int extend[5];
} Wheel;

Wheel wheels[5];

void trans(void) {
  for(int i = 0; i < 5; i++) {
    Wheel& w = wheels[i];
    for(int j = 0; j < w.num; j++) {
      w.start[j] += w.speed;
      if(w.start[j] >= 360) w.start[j] -= 360;
    }
  }
}

bool check(void) {
  for(int i = 0; i < 360; i++) {
    int cnt = 0;
    for(int j = 0; j < 5; j++) {
      for(int jj = 0; jj < wheels[j].num; jj++) {
        int s = wheels[j].start[jj], e = (s + wheels[j].extend[jj]) % 360;
        if((i >= s && i <= e && (s <= e)) || ((i >= s || i <= e) && (s > e))) { cnt++; break; }
      }
    }
    if(cnt == 5) return 1;
  }
  return false;
}

int main(void) {
  ifstream fin ("spin.in");
  ofstream fout ("spin.out");
  for(int i = 0; i < 5; i++) {
    fin >> wheels[i].speed >> wheels[i].num;
    for(int j = 0; j < wheels[i].num; j++) {
      fin >> wheels[i].start[j] >> wheels[i].extend[j];
    }
  }

  int time = 0;
  while(time < TimeLimits) {
    if(check()) { fout << time << endl; return 0;  }
    trans();
    time++;
  }

  fout << "none" << endl;

  return 0;
}
