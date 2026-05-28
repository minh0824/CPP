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

int n, a[nmax];
ll k;

bool check(ll mid) {
  ll cnt{};
  for (int i = 1; i <= n; ++i) {
    cnt+=upper_bound(a+i+1, a+n+1, mid+a[i])-a-i-1;
  }
  return cnt<k;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  // for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  // cout << endl;
  // cout << check1(6);
  ll l = 1, r = a[n]-a[0], ans{};
  while (l<=r) {
    ll mid = l + (r-l)/2;
    if (check(mid)) {
      l = mid+1;
      ans=l;
    } else r = mid-1;
  }
  cout << ans << endl;
  return 0;
}
