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
const int nmax = 1e6 + 7;

int n, k, a[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  deque<int> dqmax, dqmin;
  int l = 1;
  ll ans{};

  for (int r = 1; r <= n; ++r) {
    cin >> a[r];

    while (!dqmax.empty() && a[dqmax.back()] <= a[r]) dqmax.pop_back();
    dqmax.push_back(r);

    while (!dqmin.empty() && a[dqmin.back()] >= a[r]) dqmin.pop_back();
    dqmin.push_back(r);

    while (!dqmax.empty() && !dqmin.empty() && a[dqmax.front()] - a[dqmin.front()] > k) {
      if (dqmax.front() == l) dqmax.pop_front();
      if (dqmin.front() == l) dqmin.pop_front();
      ++l;
    }

    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}
