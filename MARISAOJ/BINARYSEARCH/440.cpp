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

int n, k;
double v[nmax], w[nmax], c[nmax];

bool check(double mid) {
  for (int i = 1; i <= n; ++i) c[i]=c[i-1]+v[i]-mid*w[i];
  double ans = c[k];
  for (int i = k; i <= n; ++i) {
    ans=max(ans, c[i]-c[i-k]);
  }
  return ans>=(double)0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
  }
  double l = 0, r = 1e9+7, eps=1e-5;
  while (r-l>eps) {
    double mid = l + (r-l)/2;
    if (check(mid)) {
      l = mid;
    } else r = mid;
  }
  cout << setprecision(3) << fixed << l << endl;
  return 0;
}
