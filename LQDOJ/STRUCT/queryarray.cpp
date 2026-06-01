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

int n, q;

struct qa {
  int a[nmax]{};
  void mod(int l, int r, int x) {
    a[l]+=x; a[r+1]-=x;
  }
  void update() {
    for (int i = 1; i <= n; ++i) a[i]+=a[i-1], cout << a[i] << ' ';
  }
};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  qa QA;
  cin >> n >> q;
  while (q--) {
    int t, l, r, x;
    cin >> t >> l >> r >> x;
    if (t==1) QA.mod(l, r, x);
    else QA.mod(l, r, -x);
  }
  QA.update();
  return 0;
}
