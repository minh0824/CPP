#include <cinttypes>
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

int n, q, s, t;
int a[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q >> s >> t;
  for (int i = 0; i <= n; ++i) cin >> a[i];
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;

  }
  // 0 4 1 8 ->
  // 0 6 3 8 ->
  // 0 4 3 8 ->
  // 0 4 8 13
  // 0 3 7 13
  // 0 8 12 18
  return 0;
}
