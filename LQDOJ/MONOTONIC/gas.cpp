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

int n, k, c[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  deque<int> dq;
  ll ans{};
  for (int i = 1; i <= n; ++i) {
    while (!dq.empty() && c[dq.back()]>=c[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front()<=i-k) dq.pop_front();
    ans += c[dq.front()];
  }
  cout << ans;
  return 0;
}
