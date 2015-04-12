/*
ID: Zhi Li
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;
typedef struct mix{
  int a, b, c;
} Mix;

Mix mixs[3];
int goal_a, goal_b, goal_c;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(void) {
  ifstream fin ("ratios.in");
  ofstream fout ("ratios.out");
  fin >> goal_a >> goal_b >> goal_c;
  for(int i = 0; i < 3; i++) fin >> mixs[i].a >> mixs[i].b >> mixs[i].c;

  int acc = 305, gd = -1, id = -1, jd = -1, kd = -1;
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      for(int k = 0; k < 100; k++) if(i + j + k > 0 && i + j + k < acc) {
        int a1 = i * mixs[0].a, b1 = i * mixs[0].b, c1 = i * mixs[0].c;
        int a2 = j * mixs[1].a, b2 = j * mixs[1].b, c2 = j * mixs[1].c;
        int a3 = k * mixs[2].a, b3 = k * mixs[2].b, c3 = k * mixs[2].c;
        int an = (a1 + a2 + a3), bn = (b1 + b2 + b3), cn = (c1 + c2 + c3);
        int tmp[] = { an, bn, cn };
        sort(tmp, tmp + 3);
        assert(tmp[2] != 0);
        int g = gcd(gcd(tmp[2], tmp[1]), tmp[0]);
        if(an == goal_a && bn == goal_b && cn == goal_c)
          if(i + j + k < acc) {
            acc = i + j + k;
            gd = 1; id = i; jd = j; kd = k;
          }

        if(an / g == goal_a && bn / g == goal_b && cn / g == goal_c)
          if(i + j + k < acc) {
            acc = i + j + k;
            gd = g; id =i; jd = j; kd = k;
          }
        }
    }
  }

  if(acc == 305) fout << "NONE" << endl;
  else
    fout << id << " " << jd << " " << kd << " " << gd << endl;


  return 0;
}
