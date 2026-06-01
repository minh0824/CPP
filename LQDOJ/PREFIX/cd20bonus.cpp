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
const int nmax = 1e3 + 7;

int n, k, a[nmax][nmax];
ll p[nmax][nmax];

ll calc(int x1, int y1, int x2, int y2) {
  return p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    }
  }
  ll ans{};
  for (int i = k; i <= n; ++i) {
    for (int j = k; j <= n; ++j) {
      ans=max(ans, calc(i-k+1, j-k+1, i, j));
    }
  }
  cout << ans;

  return 0;
}
