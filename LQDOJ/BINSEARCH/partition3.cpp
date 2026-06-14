#include <bits/stdc++.h>

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

int n, k, a[nmax];

bool check(int d) {
  ll cur{};
  for (int i = 1; i <= n; ++i) {
    cur+=a[i]/d;
    if (cur>=k) return 1;
  }
  return cur>=k;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // freopen("PART.INP", "r", stdin);
  // freopen("PART.OUT", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 0, r = 1e9+7;
  while (r>l) {
    int mid = (l+r+1)/2;
    if (check(mid)) {
      l = mid;
    } else r = mid-1;
  }
  cout << l << endl;
  return 0;
}
