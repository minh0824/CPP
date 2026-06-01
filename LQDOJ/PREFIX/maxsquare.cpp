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
const int nmax = 3e3 + 7;

int n, m, a[nmax][nmax];
ll S;
ll p[nmax][nmax];

ll calc(int x1, int y1, int x2, int y2) {
  return p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
}

bool check(int k) {
  for (int i = k; i <= n; ++i) {
    for (int j = k; j <= m; ++j) {
      if (calc(i-k+1, j-k+1, i, j)<=S) return 1;
    }
  }
  return 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> S;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    }
  }
  int ans{};
  int l = 1, r = 3000;
  while (l<=r) {
    int mid = (l+r)/2;
    if (check(mid)) {
      l=mid+1;
      ans=max(ans,mid);
    } else {
      r = mid-1;
    }
  }
  cout << 1ll*ans*ans;
  return 0;
}
