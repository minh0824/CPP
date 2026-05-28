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

int n, m;
ll k;

bool check(ll mid) {
  ll cnt{};
  for (int i = 1; i <= min(mid, 1ll*n); ++i) {
    cnt+=min(1ll*m*i, mid)/i;
  }
  return cnt>=k;
}

int check1(int mid) {
  ll cnt{};
  for (int i = 1; i <= min(mid, n); ++i) {
    cnt+=min(m*i, mid)/i;
  }
  return cnt;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  ll l = 1, r = 1e10+7, ans{};
  while (l<=r) {
    ll mid = (l+r)/2;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else l = mid + 1;
  }
  cout << ans;

  return 0;
}
