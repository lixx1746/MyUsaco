/*
ID: Zhi Li
PROG: shopping
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

map<int, int> mp;

int dp[6][6][6][6][6];

typedef struct special {
  int n;
  int product_code[6], need_num[6];
  int reduced_price;
} Special;
Special specials[105];

int s, b;
typedef struct product {
  int product_code;
  int num;
  int price;
} Product;
Product products[6];

int main(void) {
  ifstream fin ("shopping.in");
  ofstream fout ("shopping.out");
  fin >> s;
  int n, code, need_num, price;
  for(int i = 1; i <= s; i++) {
    fin >> n;
    specials[i].n = n;
    for(int j = 1; j <= n; j++) {
      fin >> code >> need_num;
      specials[i].product_code[j] = code;
      specials[i].need_num[j] = need_num;
    }
    fin >> price;
    specials[i].reduced_price = price;
  }
  vector<int> buy(5, 0);
  fin >> b;
  for(int i = 1; i <= b; i++) {
    fin >> code >> need_num >> price;
    mp[code] = i - 1;
    products[i].product_code = code;
    products[i].num = need_num;
    products[i].price = price;
    buy[i - 1] = need_num;
  }


  for(int p0 = 0; p0 <= buy[0]; p0++) {
    for(int p1 = 0; p1 <= buy[1]; p1++) {
      for(int p2 = 0; p2 <= buy[2]; p2++) {
        for(int p3 = 0; p3 <= buy[3]; p3++) {
          for(int p4 = 0; p4 <= buy[4]; p4++) {
            int s = p0 * products[1].price + p1 * products[2].price + p2 * products[3].price +
              p3 * products[4].price + p4 * products[5].price;
            dp[p0][p1][p2][p3][p4] = s;
          }
        }
      }
    }
  }

  for(int i = 1; i <= s; i++) {
    for(int p0 = 0; p0 <= buy[0]; p0++) {
      for(int p1 = 0; p1 <= buy[1]; p1++) {
        for(int p2 = 0; p2 <= buy[2]; p2++) {
          for(int p3 = 0; p3 <= buy[3]; p3++) {
            for(int p4 = 0; p4 <= buy[4]; p4++) if(p0 + p1 + p2 + p3 + p4 != 0) {
              Special sp = specials[i];
              int flag = 1;
              int need[] = {p0, p1, p2, p3, p4};
              vector<int> get(5, 0);
              for(int ii = 1; flag && ii <= sp.n; ii++) {
                if(!mp.count(sp.product_code[ii])) flag = 0;
                else if(need[mp[sp.product_code[ii]]] < sp.need_num[ii]) flag = 0;
                else {
                  get[mp[sp.product_code[ii]]] = sp.need_num[ii];
                }
              }
              if(flag) {
                int t0 = p0 - get[0], t1 = p1 - get[1], t2 = p2 - get[2], t3 = p3 - get[3], t4 = p4 - get[4];
                dp[p0][p1][p2][p3][p4] = min(dp[p0][p1][p2][p3][p4], dp[t0][t1][t2][t3][t4] + sp.reduced_price);
              }
            }
          }
        }
      }
    }
  }

  fout << dp[buy[0]][buy[1]][buy[2]][buy[3]][buy[4]] << endl;

  return 0;
}
