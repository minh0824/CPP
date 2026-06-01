#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

struct bang {
  int x, y;
  bang(int a, int b) { x = a, y = b;}
  ll calc() {
    // cout << x << ' ' << y << endl;
    int sx = x/3, sy = y/3;
    ll cnt{};
    for (int i = 1; i <= y; ++i) {
      if (i%3==0) {
        cnt+=min(i, x)+sx-min(i, x)/3;
        // cout << min(i, x)+sx-min(i, x)/3 << endl;
      } else {
        cnt+=sx-min((i-1),x)/3;
        // cout << sx-min((i-1), x)/3 << endl;
      }
    }
    return cnt;
  }
};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1>x2) swap(x1, x2);
  if (y1>y2) swap(y1, y2);
  bang a1(x2, y2), a2(x1, y2), a3(x2, y1), a4(x1, y1);
  // cout << a1.calc() << endl;
  // cout << a2.calc() << endl;
  // cout << a3.calc() << endl;
  // cout << a4.calc() << endl;
  cout << a1.calc()-a2.calc()-a3.calc()+a4.calc();
  return 0;
}
