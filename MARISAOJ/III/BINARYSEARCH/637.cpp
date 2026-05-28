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

int n;
ll a[nmax], p[nmax], S;

bool check(int len) {
  for (int i = 1; i <= n; ++i) {
    if (i-len>=0 && p[i]-p[i-len]<=S) return 1;
  }
  return 0;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> S;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i]=p[i-1]+a[i];
  }
  int l = 0, r = 2e5+7, ans = -1;
  while (r>=l) {
    int mid = l+(r-l)/2;
    if (check(mid)) {
      l = mid+1;
      ans = mid;
    } else r = mid-1;
  }
  cout << ans;
  return 0;
}
