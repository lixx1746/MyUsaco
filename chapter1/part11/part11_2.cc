/*
ID: Zhi Li
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    int c = 1, g = 1;
    for(int i = 0; i < (int) a.size(); i++) c *= ((a[i] - 'A') + 1);
    for(int j = 0; j < (int) b.size(); j++) g *= ((b[j] - 'A') + 1);
    fout << (c % 47 == g % 47 ? "GO" : "STAY") << endl;
    return 0;

}
