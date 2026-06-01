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

int n, m, a[nmax][nmax];
ll p[nmax][nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    }
  }
  int q; cin >> q;
  while (q--) {

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
  cout << endl;
  }
  return 0;
}
