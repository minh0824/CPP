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
const int nmax = 2e5 + 7;

ll a[nmax], cnt[nmax], upd[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int l, r; cin >> l >> r;
    ++cnt[l], --cnt[r+1];
    upd[l]+=l-1, upd[r+1]-=l-1;
  }
  for (int i = 1; i <= n; ++i) {
    cnt[i]+=cnt[i-1], upd[i]+=upd[i-1];
    cout << i*cnt[i]-upd[i] << ' ';
  }
  return 0;
}
